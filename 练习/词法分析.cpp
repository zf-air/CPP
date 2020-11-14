#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct{
    string formula;//表达式
}grammerElement;
grammerElement form[100]; //原始文法的产生式集

string ter_symbol;//终结符号
string non_ter;//非终结符号
string inter_symbol;//输入符号
string first_set[100];//非终结符的FIRST集
string follow_set[100];//非终结符的FOLLOW集
int M[200][200];//分析表

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
//    int flag=1;
//    while(flag){
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
    }
}

//获取所有非终结符的first集合
void First(){
    for(int i=0;i<non_ter.size();i++){
        getFirst(non_ter[i],i);
    }
}

int main()
{
    //输入产生式
    int i=0;
    string s;
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

    //统计终结符和非终结符
    init_NT();
    cout<<"终结符:"<<ter_symbol<<endl;
    cout<<"非终结符:"<<non_ter<<endl;

    //获取first集合
    First();
    cout<<"first集合:"<<endl;
    for(int i=0;i<non_ter.size();i++){
        cout<<non_ter[i]<<":"<<first_set[i]<<endl;
    }

    return 0;
}

