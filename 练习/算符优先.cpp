#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct{
    string formula;//表达式
}grammerElement;
grammerElement form[100]; //原始文法的产生式集

string ter_symbol;//终结符号
string non_ter;//非终结符号
int sum=0; //记录产生式个数
int firstvt[200][200];//firstvt表
int lastvt[200][200];//lastvt表
string firstset[200];//firstvt集合
string lastset[200];//lastvt集合
char M[200][200];//算符优先表

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

void setFirstVt(){
    //初始化firstvt表
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_symbol.size();j++)
            firstvt[i][j]=false;
    }
    //遍历产生式
    for(int i=0;i<sum;i++){
        //第0个符号
        char ch0=form[i].formula[0];
        //获取第0个符号的下标
        int i_ch0=getNonSite(ch0);
        //第三个符号
        char ch3=form[i].formula[3];        
        //如果是终结符
        if(isTer(ch3)){
            //获取第三个符号的下标
            int i_ch3=getTerSite(ch3);
            //设置firstvt表
            firstvt[i_ch0][i_ch3]=true;
        }
        else{
            if(form[i].formula.size()>4){
                //第四个符号
                char ch4=form[i].formula[4];
                //判断第四个符号是不是终结符
                if(isTer(ch4)){
                    //获取第四个符号的下标
                    int i_ch4=getTerSite(ch4);
                    //设置firstvt表
                    firstvt[i_ch0][i_ch4]=true;
                }
            }
        }
    }

    //设置栈
    stack<string> ss;
    //把所有为真的符号对(P,a)入栈
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_symbol.size();j++){
            if(firstvt[i][j]){
                string st="";
                st+=non_ter[i];
                st+=ter_symbol[j];
                ss.push(st);
            }
        }
    }

    //遍历栈
    while(!ss.empty()){
        //获取栈顶元素s
        string s=ss.top();
        ss.pop();
        //第三个符号,非终结符Q
        char ch3=s[0];
        //遍历所有产生式
        for(int i=0;i<sum;i++){
            if(form[i].formula[3]==ch3){
                //获取第0个符号
                char ch0=form[i].formula[0];
                //获取第0个符号的下标
                int i_ch0=getNonSite(ch0);
                //获取终结符a下标
                int i_ch_a=getTerSite(s[1]);
                if(!firstvt[i_ch0][i_ch_a]){
                    firstvt[i_ch0][i_ch_a]=true;
                    string st="";
                    st+=ch0;
                    st+=s[1];
                    ss.push(st);
                }
            }
        }
    }
}

void setLastVt(){
    //初始化lastvt表
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_symbol.size();j++)
            lastvt[i][j]=false;
    }
    //遍历产生式
    for(int i=0;i<sum;i++){
        int length=form[i].formula.size();
        //第0个符号
        char ch0=form[i].formula[0];
        //获取第0个符号的下标
        int i_ch0=getNonSite(ch0);
        //最后一个符号
        char chn1=form[i].formula[length-1];
        //如果是终结符
        if(isTer(chn1)){
            //获取第三个符号的下标
            int i_chn1=getTerSite(chn1);
            //设置lastvt表
            lastvt[i_ch0][i_chn1]=true;
        }
        else{
            if(form[i].formula.size()>4){
                //倒数第二个符号
                char chn2=form[i].formula[length-2];
                //判断倒数第二个符号是不是终结符
                if(isTer(chn2)){
                    //获取倒数第二个符号的下标
                    int i_chn2=getTerSite(chn2);
                    //设置lastvt表
                    lastvt[i_ch0][i_chn2]=true;
                }
            }
        }
    }

    //设置栈
    stack<string> ss;
    //把所有为真的符号对(P,a)入栈
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_symbol.size();j++){
            if(lastvt[i][j]){
                string st="";
                st+=non_ter[i];
                st+=ter_symbol[j];
                ss.push(st);
            }
        }
    }

    //遍历栈
    while(!ss.empty()){
        //获取栈顶元素s
        string s=ss.top();
        ss.pop();
        //最后一个符号,非终结符Q
        char chn1=s[0];
        //遍历所有产生式
        for(int i=0;i<sum;i++){
            int length=form[i].formula.size();
            if(form[i].formula[length-1]==chn1){
                //获取第0个符号
                char ch0=form[i].formula[0];
                //获取第0个符号的下标
                int i_ch0=getNonSite(ch0);
                //获取终结符a下标
                int i_ch_a=getTerSite(s[1]);
                if(!lastvt[i_ch0][i_ch_a]){
                    lastvt[i_ch0][i_ch_a]=true;
                    string st="";
                    st+=ch0;
                    st+=s[1];
                    ss.push(st);
                }
            }
        }
    }
}

void setYouxianTable(){
    //初始化优先关系表
    for(int i=0;i<ter_symbol.size();i++){
        for(int j=0;j<ter_symbol.size();j++){
            M[i][j]=' ';
        }
    }
    //遍历产生式
    for(int i=0;i<sum;i++){
        int length=form[i].formula.size();
        for(int j=3;j<length-1;j++){
            char ch1=form[i].formula[j];
            char ch2=form[i].formula[j+1];
            //aa,两个相邻的终结符
            if(isTer(ch1)&&isTer(ch2)){
                int i_ch1=getTerSite(ch1);
                int i_ch2=getTerSite(ch2);
                M[i_ch1][i_ch2]='=';
            }
            //aAa
            if(j+2<length&&isTer(ch1)&&isNon(ch2)&&isTer(form[i].formula[j+2])){
                char ch3=form[i].formula[j+2];
                int i_ch1=getTerSite(ch1);
                int i_ch3=getTerSite(ch3);
                M[i_ch1][i_ch3]='=';
            }
            //aA
            if(isTer(ch1)&&isNon(ch2)){
                int i_ch1=getTerSite(ch1);
                int i_ch2=getNonSite(ch2);
                for(int k=0;k<ter_symbol.size();k++){
                    if(firstvt[i_ch2][k]){
                        M[i_ch1][k]='<';
                    }
                }
            }
            //Aa
            if(isNon(ch1)&&isTer(ch2)){
                int i_ch1=getNonSite(ch1);
                int i_ch2=getTerSite(ch2);
                for(int k=0;k<ter_symbol.size();k++){
                    if(lastvt[i_ch1][k]){
                        M[k][i_ch2]='>';
                    }
                }
            }
        }
    }
}
void addString(string &s,char ch){
    string s2="";
    s2+=ch;
    s2+=s;
    s=s2;
}
void Yuce(string s){
    char ss[200];
    int k=0;//ss的下标
    ss[k]='#';
    int i=0;//s的下标
    int j=0;
    do{
        if(isTer(ss[k])){
            j=k;
        }
        else
            j=k-1;
        //获取a的下标
        int i_si=getTerSite(s[i]);
        //获取栈顶的下标
        int i_ss=getTerSite(ss[j]);
        //栈顶条件满足
        while(M[i_ss][i_si]=='>'){
            int i_j=0;
            int i_j_1=0;
            //寻找素短语的头
            do{
                i_j=getTerSite(ss[j]);
                if(isTer(ss[j-1]))
                    j=j-1;
                else
                    j=j-2;
                i_j_1=getTerSite(ss[j]);
            }while(M[i_j_1][i_j]=='=');
            //开始规约,j+1->k
            int n=j+1;
            for(int l=0;l<sum;l++){
                int m;
                int flag=0;
                for(m=3;m<form[l].formula.size();m++){
                    if(isNon(form[l].formula[m])){
                        continue;
                    }
                    else{
                        if(form[l].formula[m]==ss[n]){
                            flag=1;
							n++;
                        }
                        else{
                        	flag=0;
                            break;
                        }
                    }
                }
                //匹配成功
                if(flag&&n>k&&m>=form[l].formula.size()){
                    k=j+1;
                    ss[k]=form[l].formula[0];
                    cout<<form[l].formula<<endl;
                    break;
                }
            }
        }
        if(M[i_ss][i_si]=='<'||M[i_ss][i_si]=='='){
            k++;
            ss[k]=s[i];
            i++;
        }
    }while(s[i]!='#');
}
void fenge(){
    cout<<"-------------------------"<<endl;
}
int main()
{
    //输入产生式
    int i=0;
    string s;
    cout<<"请输入文法:"<<endl;
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

    //构造firstvt表
    cout<<"firstvt集合:"<<endl;
    setFirstVt();
    cout<<"   ";
    for(int i=0;i<ter_symbol.size();i++)
        cout<<" "<<ter_symbol[i]<<" ";
    cout<<endl;
    for(int i=0;i<non_ter.size();i++){
        cout<<" "<<non_ter[i]<<" ";
        for(int j=0;j<ter_symbol.size();j++){
            cout<<" "<<firstvt[i][j]<<" ";
        }
        cout<<endl;
    }
    fenge();

    //构造lastvt表
    cout<<"lastvt集合:"<<endl;
    setLastVt();
    cout<<"   ";
    for(int i=0;i<ter_symbol.size();i++)
        cout<<" "<<ter_symbol[i]<<" ";
    cout<<endl;
    for(int i=0;i<non_ter.size();i++){
        cout<<" "<<non_ter[i]<<" ";
        for(int j=0;j<ter_symbol.size();j++){
            cout<<" "<<lastvt[i][j]<<" ";
        }
        cout<<endl;
    }
    fenge();

    //构造firstvt和lastvt集合
    for(int i=0;i<non_ter.size();i++){
        for(int j=0;j<ter_symbol.size();j++){
            if(firstvt[i][j]){
                firstset[i]+=ter_symbol[j];
            }
            if(lastvt[i][j]){
                lastset[i]+=ter_symbol[j];
            }
        }
    }
    cout<<"firstvt集合:"<<endl;
    for(int i=0;i<non_ter.size();i++)
        cout<<non_ter[i]<<":"<<firstset[i]<<endl;
    fenge();
    cout<<"lastvt集合:"<<endl;
    for(int i=0;i<non_ter.size();i++)
        cout<<non_ter[i]<<":"<<lastset[i]<<endl;
    fenge();

    //构造优先关系表
    cout<<"优先关系表:"<<endl;
    setYouxianTable();
    cout<<"   ";
    for(int i=0;i<ter_symbol.size();i++)
        cout<<" "<<ter_symbol[i]<<" ";
    cout<<endl;
    for(int i=0;i<ter_symbol.size();i++){
        cout<<" "<<ter_symbol[i]<<" ";
        for(int j=0;j<ter_symbol.size();j++){
            cout<<" "<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    fenge();

    //预测程序
    cout<<"请输入字符串:";
    cin>>s;
    Yuce(s);
    fenge();

}

