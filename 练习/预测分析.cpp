#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef struct{
    string formula;//表达式
}grammerElement;
grammerElement form[100]; //原始文法的产生式集

string ter_symbol;//终结符号
string ter_table;//预测表用的终结符
string non_ter;//非终结符号
string inter_symbol;//输入符号
string first_set[100];//非终结符的FIRST集
string follow_set[100];//非终结符的FOLLOW集
string M[200][200];//分析表
stack<char> ss;//符号栈
int sum=0; //记录产生式个数

//大写字母是非终结符
int isUpper(char ch){
    if(ch>='A'&&ch<='Z')
        return true;
    return false;
}

//根据终结符串判断是否是终结符
int isTer(char a){
    for(int i=0;i<ter_symbol.size();i++)
        if(ter_symbol[i]==a)
            return true;
    return false;
}
//根据非终结符串判断是否是非终结符
int isNon(char a){
    for(int i=0;i<non_ter.size();i++){
        if(non_ter[i]==a)
            return true;
    }
    return false;
}

//获取非终结符的下标
int getNonSite(char ch){
    int j=0;
    for(;j<non_ter.size();j++){
        if(non_ter[j]==ch){
            break;
        }
    }
    return j;
}
//获取终结符的下标
int getTerSite(char ch){
    int j=0;
    for(;j<ter_symbol.size();j++){
        if(ter_symbol[j]==ch){
            break;
        }
    }
    return j;
}

//统计终结符和非终结符
void init_NT(){
    //大写为非终结符，其他为终结符,0是终结符
    int i,j;
    for(i=0;i<sum;i++){
        for(j=0;j<form[i].formula.size();j++){
            char ch=form[i].formula[j];
            if(ch=='-'||ch=='>'||ch==' ')
                continue;
            //终结符
            if(!isUpper(ch)){
                //查找是否存在
                int flag=0;
                for(int k=0;k<ter_symbol.size();k++){
                    if(ter_symbol[k]==ch){
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    ter_symbol+=ch;
            }
            //非终结符
            else{
                //查找是否存在
                int flag=0;
                for(int k=0;k<non_ter.size();k++){
                    if(non_ter[k]==ch){
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    non_ter+=ch;
            }
        }
    }
}

//查找first集合是否有空
//有空返回true，没有空返回false
int is_first_set_0(int col){
    for(int i=0;i<first_set[col].size();i++){
        if(first_set[col][i]=='0'){
            return true;
        }
    }
    return false;
}

//给A的first添加终结符
//添加了返回1，未添加返回0
int addfirst_Ter(char ch,int col){
    int t_flag=0;
    int flag=0;
    for(int j=0;j<first_set[col].size();j++){
        if(first_set[col][j]==ch){
            t_flag=1;
            break;
        }
    }
    if(!t_flag){
        first_set[col]+=ch;
        flag=1;
    }
    return flag;
}

//给A的first添加非终结符的first
//添加了返回1，未添加返回0
int addfirst_Non(int i_ch,int col){
    int non_A_size=first_set[col].size();
    int flag=0;
    //把ch的first集加到A的first集,并去重
    for(int j=0;j<first_set[i_ch].size();j++){
        int t_flag=0;
        for(int k=0;k<non_A_size;k++){
            if(first_set[i_ch][j]==first_set[col][k]){
                t_flag=1;
                break;
            }
        }
        if(!t_flag){
            first_set[col]+=first_set[i_ch][j];
            flag=1;
        }
    }
    return flag;
}

//获取一个非终结符的first集合
//更改了返回1，未更改返回0
int getFirst(char A,int col){
    int flag=0;
    //遍历所有文法
    for(int i=0;i<sum;i++){
        // 查找该字符开头的文法
        if(A==form[i].formula[0]){
            //找出第一个first集不含空或者是非终结符
            int t=3;
            //是非终结符
            while(t<form[i].formula.size()&&isNon(form[i].formula[t])){
                //获取位置
                int i_t=0;
                i_t=getNonSite(form[i].formula[t]);
                //含空
                if(is_first_set_0(i_t)){
                    t++;
                }
                else{
                    break;
                }
            }

            int t_flag=0;
            //全是非终结符，并且含空集，到头了，添加0
            if(t==form[i].formula.size()){
                t--;
                //给A添加终结符0
                t_flag=addfirst_Ter('0',col);
            }
            //找到了终结符
            else if(isTer(form[i].formula[t])){
                //给A添加终结符
                t_flag=addfirst_Ter(form[i].formula[t],col);
                t--;
            }
            for(int j=3;j<=t;j++){
                char ch=form[i].formula[j];
                //获取ch的下标
                int i_ch;
                i_ch=getNonSite(ch);
                t_flag=addfirst_Non(i_ch,col);
            }
            if(t_flag)
                flag=1;
        }
    }
    return flag;
}

//获取所有非终结符的first集合
void First(){
    int flag=1;
    while(flag){
        flag=0;
        int t_flag=0;
        for(int i=0;i<non_ter.size();i++){
            t_flag=getFirst(non_ter[i],i);
            if(t_flag)
                flag=1;
        }
    }
}

//给A的follow添加终结符
//添加了返回1，未添加返回0
int addFollow_Ter(char ch,int col){
    int t_flag=0;
    int flag=0;
    for(int j=0;j<follow_set[col].size();j++){
        if(follow_set[col][j]==ch){
            t_flag=1;
            break;
        }
    }
    if(!t_flag){
        follow_set[col]+=ch;
        flag=1;
    }
    return flag;
}

//给A的follow添加非终结符的first除了0
//添加了返回1，未添加返回0
int addfollow_NonFirst(int i_ch,int col){
    int non_A_size=follow_set[col].size();
    int flag=0;
    //把ch的first集除了0加到A的follow集,并去重
    for(int j=0;j<first_set[i_ch].size();j++){
        if(first_set[i_ch][j]!='0'){
            int t_flag=0;
            for(int k=0;k<non_A_size;k++){
                if(first_set[i_ch][j]==follow_set[col][k]){
                    t_flag=1;
                    break;
                }
            }
            if(!t_flag){
                follow_set[col]+=first_set[i_ch][j];
                flag=1;
            }
        }
    }
    return flag;
}

//把A的follow添加到非终结符的follow
//添加了返回1，未添加返回0
int addfollow_NonFollow(int i_ch,int col){
    int non_ch_size=follow_set[i_ch].size();
    int flag=0;
    //把A的follow添加到ch的follow,并去重
    for(int j=0;j<follow_set[col].size();j++){
        int t_flag=0;
        for(int k=0;k<non_ch_size;k++){
            if(follow_set[i_ch][k]==follow_set[col][j]){
                t_flag=1;
                break;
            }
        }
        if(!t_flag){
            follow_set[i_ch]+=follow_set[col][j];
            flag=1;
        }
    }
    return flag;
}

//获取一个非终结符的follow集合
int getFollow(char A,int col){
    int flag=0;
    //遍历所有文法
    for(int i=0;i<sum;i++){
        // 查找该字符开头的文法
        if(A==form[i].formula[0]){
            int t_flag=0;
            int len=form[i].formula.size();

            // 1.添加first集
            int t=len-1;
            //找到第一个终结符或者不含空的非终结符
            while(t>=3&&isNon(form[i].formula[t])){
                int i_t;
                i_t=getNonSite(form[i].formula[t]);
                //含空
                if(is_first_set_0(i_t)){
                    t--;
                }else{
                    break;
                }
            }

            //如果前面全是含空的非终结符
            if(t<3){
                continue;
            }
            char ch=form[i].formula[t];
            //如果是终结符
            if(isTer(ch)){
                if(ch!='0'){
                    if(t-1>=3){
                        //前一个是非终结符
                        if(isNon(form[i].formula[t-1])){
                            //把他加到非终结符中
                            int i_t;
                            i_t=getNonSite(form[i].formula[t-1]);
                            t_flag=addFollow_Ter(ch,i_t);
                            //更新t,前面全是含空的非终结符或者是最后一个
                            t++;
                        }
                    }
                }
            }
            //如果是非终结符不含空,或者终结符前面全是含空的非终结符或者是最后一个
            //最后一个直接不执行
            for(int k=len-1;k>=t+1;k--){
                //后一个
                int i_ch;
                i_ch=getNonSite(form[i].formula[k]);
                //前一个
                int i_t;
                i_t=getNonSite(form[i].formula[k-1]);

                t_flag=addfollow_NonFirst(i_ch,i_t);
            }

            //2.添加follow集
            //从后往前找出第一个first不含空或者是终结符
            t=len-1;
            //把A的follow集加到末尾非终结符的follow集
            if(isNon(form[i].formula[t])){
                int i_t;
                i_t=getNonSite(form[i].formula[t]);
                t_flag=addfollow_NonFollow(i_t,col);
            }
            //是非终结符
            while(t>=3&&isNon(form[i].formula[t])){
                //获取位置
                int i_t=0;
                i_t=getNonSite(form[i].formula[t]);
                //含空
                if(is_first_set_0(i_t)){
                    t--;
                }
                else{
                    break;
                }
            }

            //如果全是非终结符并且含有空集，到头了
            if(t<3){
                continue;
            }
            //如果遇到了终结符,前面都是含空的非终结符或者是最后一个
            else if(isTer(form[i].formula[t])){
                continue;
            }
            //遇到了第一个不含空的非终结符
            else if(isNon(form[i].formula[t])){

                //把A的follow集加到他的follow集
                int i_ch;
                i_ch=getNonSite(form[i].formula[t]);
                t_flag=addfollow_NonFollow(i_ch,col);
            }

            if(t_flag)
                flag=1;
        }
    }
    return flag;
}

//获取follow集合
void Follow(){
    int flag=1;
    //给开始符号添加#
    follow_set[0]+='#';
    while(flag){
        flag=0;
        int t_flag=0;
        for(int i=0;i<non_ter.size();i++){
            t_flag=getFollow(non_ter[i],i);
            if(t_flag)
                flag=1;
        }
    }
}

//获取预测分析表用的终结符下标
int getTer_table(char ch){
    for(int i=0;i<ter_table.size();i++){
        if(ter_table[i]==ch)
            return i;
    }
    return -1;
}

//构造预测分析表
void setTable(){
    //遍历所有产生式
    for(int i=0;i<sum;i++){
        string s=form[i].formula;
        //最左边的符号
        char A=s[0];
        //获取非终结符A的下标
        int i_A;
        i_A=getNonSite(A);
        //右部最左边的第一个符号
        char ch=s[3];
        //是终结符
        if(isTer(ch)){
            if(ch!='0'){
                //获取终结符ch的下标
                int i_ch;
                i_ch=getTer_table(ch);
                //把产生式加入到分析表M[A,ch]
                M[i_A][i_ch]=s;
            }
            else{
                //遍历A的follow集合
                for(int j=0;j<follow_set[i_A].size();j++){
                    char b=follow_set[i_A][j];
                    //获取b的下标
                    int i_b;
                    i_b=getTer_table(b);
                    //产生式添加到M[A,b]中
                    M[i_A][i_b]=s;
                }
            }
        }
        //非终结符
        else{
            //获取非终结符下标
            int i_ch;
            i_ch=getNonSite(ch);
            //遍历ch的first集合
            int t_flag=0; //判断ch的first集合是否有空
            for(int j=0;j<first_set[i_ch].size();j++){
                char a=first_set[i][j];
                //不为空，把产生式添加进分析表M[A,a]
                if(a!='0'){
                    //获取终结符a的下标
                    int i_a;
                    i_a=getTer_table(a);
                    M[i_A][i_a]=s;
                }
                //为空
                else{
                    t_flag=1;
                    continue;
                }
            }
            //遍历follow(A)的元素b,把产生式加入到M[A,b]
            if(t_flag){
                //遍历A的follow集合
                for(int j=0;j<follow_set[i_A].size();j++){
                    char b=follow_set[i_A][j];
                    //获取b的下标
                    int i_b;
                    i_b=getTer_table(b);
                    //产生式添加到M[A,b]中
                    M[i_A][i_b]=s;
                }
            }
        }
    }
}

int Yuce(string s){
    int t=0;//步骤
    int i=0; //i作为s的下标
    //压入#和开始符号
    ss.push('#');
    ss.push(non_ter[0]);

    int flag=1;
    while(flag){
        //获取栈顶元素
        char ch=ss.top();
        //终结符
        if(isTer(ch)){
            if(i<s.size()&&ch==s[i]){
                //分析成功
                if(ch=='#'){
                    cout<<t;
                    cout<<'#';
                    cout<<'#';
                    flag=false;
                    return true;
                }
                //终结符匹配
                else{
                    ss.pop();
                    i++;
                }
            }
            else
                return false;
        }
        //非终结符
        else if(isNon(ch)){
            //获取非终结符下标
            int i_ch;
            i_ch=getNonSite(ch);
            //获取终结符下标
            int i_a;
            i_a=getTer_table(s[i]);
            //查找分析表中是否有产生式
            if(M[i_ch][i_a]!=""){
                ss.pop();
                string ts=M[i_ch][i_a];
//                cout<<"ts:"<<ts<<endl;
                for(int j=ts.size()-1;j>=3;j--){
                    if(ts[j]=='0'){
                        continue;
                    }
                    else{
                        ss.push(ts[j]);
                    }
                }
            }
            else
                return false;
        }
        else{
        	flag=false;
		}
        stack<char> ss2;
        while(!ss.empty()){       	
            ss2.push(ss.top());
            ss.pop();           
        }
        cout<<endl;
        while(!ss2.empty()){
            ss.push(ss2.top());
			cout<<ss.top();
            ss2.pop();
        }
    }

    return true;
}
void fenge(){
    cout<<"-------------------------"<<endl;
}

int main()
{
    //输入产生式
    int i=0;
    string s;
    cout<<"请输入文法:";
    cin>>s;
    while(s[0]!='#'){
        char ch=s[0];
        string s2;
        s2+=ch;
        s2+="->";
        for(int j=3;j<s.size();j++){
            string s3=s2;
            while(j<s.size()&&s[j]!='|'){
                s3+=s[j];
                j++;
            }
            form[i].formula=s3;
            i++;
        }
        cin>>s;
    }
    sum=i; //sum代表个数，循环用i<sum
    cout<<"sum:"<<sum<<endl;
    cout<<"所有文法:"<<endl;
    for(int i=0;i<sum;i++){
        cout<<form[i].formula<<endl;
    }
    fenge();

    //统计终结符和非终结符
    init_NT();
    cout<<"终结符:"<<ter_symbol<<endl;
    cout<<"非终结符:"<<non_ter<<endl;
    fenge();

    //获取first集合
    First();
    cout<<"first集合:"<<endl;
    for(int i=0;i<non_ter.size();i++){
        cout<<non_ter[i]<<":"<<first_set[i]<<endl;
    }
    fenge();

    //获取follow集合
    Follow();
    cout<<"follow集合:"<<endl;
    for(int i=0;i<non_ter.size();i++){
        cout<<non_ter[i]<<":"<<follow_set[i]<<endl;
    }
    fenge();

    //构造预测分析表用的终结符
    for(int i=0;i<ter_symbol.size();i++){
        if(ter_symbol[i]!='0'){
            ter_table+=ter_symbol[i];
        }
    }
    ter_table+='#';
    cout<<"ter_table:"<<ter_table<<endl;
    //初始化预测分析表
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_table.size();j++){
            M[i][j]="";
        }
    }
    //构造预测分析表
    setTable();
    //输出预测分析表
    cout<<"预测分析表:"<<endl;
    //7个空格
    cout<<"       |";
    for(int i=0;i<ter_table.size();i++){
        //获取终结符a
        char a=ter_table[i];
        cout<<"   "<<a<<"   |";
    }
    cout<<endl;
    for(int i=0;i<non_ter.size();i++){
        //获取非终结符
        char A=non_ter[i];
        cout<<"   "<<A<<"   |";
        for(int j=0;j<ter_table.size();j++){
            //获取终结符a
            char a=ter_table[j];
            cout<<M[i][j];
            for(int k=0;k<(7-M[i][j].size());k++){
                cout<<" ";
            }
            cout<<"|";
        }
        cout<<endl;
    }
    fenge();

    string s2;
    cout<<"请输入串:";
    cin>>s2;
    int flag=Yuce(s2);
    if(flag)
        cout<<"预测成功!"<<endl;
    else
        cout<<"预测失败!"<<endl;
    return 0;
}

