#include <iostream>
#include <stack>
#include <string>

using namespace std;

//变量结构体
struct var{
    string var_name;//变量名
    int start;//开始位置
    int end;//结束位置
    int bc;//步长
};

//判断两符号的优先关系
char Precede(char t1, char t2){
    int i=0,j=0;

    //运算符之间的优先级制作成一张表格
    char pre[7][7]={
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}
    };
    switch(t1){
        case '+': i=0; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=3; break;
        case '(': i=4; break;
        case ')': i=5; break;
        case '=': i=6; break;
    }
    switch(t2){
        case '+': j=0; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=3; break;
        case '(': j=4; break;
        case ')': j=5; break;
        case '=': j=6; break;
    }
    return pre[i][j];
}

//判断c是否为运算符
bool isOperator(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
        return true;
    default:
        return false;
    }
}

//判断c是否为数字
bool isNumber(char c){
    if(c>='0'&&c<='9')
        return true;
    return false;
}

//判断是否是第三种，把第三种单独处理
bool isVariable(char c){
    //符号c仅用于判断 并不代表是变量名
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||c==':'||c=='|')
        return true;
    return false;
}

int calculate(string s){
    //运算符栈
    stack<int> s_operator;
    //数字栈
    stack<int> s_number;
    int length=(int)s.length();
    int i;
    int res=-1;
    cout<<"length:"<<length<<endl;

    for(i=0;i<length;i++){

        //如果是数字
        if(isNumber(s[i])){
            int num=s[i]-'0';
            i++;
            while(i<length&&isNumber(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            s_number.push(num);
            if(i<=length)
                i--;
        }

        //如果是运算符
        else if(isOperator(s[i])){
            if(s_operator.empty()){
                s_operator.push(s[i]);
                continue;
            }
            else{
                char t1,t2;
                t1=s_operator.top();
                t2=s[i];
                cout<<"t1:"<<t1<<endl;
                cout<<"t2:"<<t2<<endl;

                switch(Precede(t1, t2))
                {
                case '<':   //当前已经压栈一个运算符（t1）比后一个运算符（t2）低时，就将t2压栈
                    cout<<"<"<<endl;
                    s_operator.push(t2);
                    break;
                case '=':
                    cout<<"="<<endl;
                    s_operator.pop();   //脱括号
                    break;
                case '>':
                {
                    cout<<">"<<endl;
                    //退栈并将运算结果压入s_number中
                    s_operator.pop();

                    //两个操作数
                    int a2=s_number.top();
                    s_number.pop();
                    int a1=s_number.top();
                    s_number.pop();
                    cout<<"a1:"<<a1<<" a2:"<<a2<<endl;

                    //a1 t1 a2,进行运算
                    int res=0;
                    if(t1=='+')
                        res=a1+a2;
                    else if(t1=='-')
                        res=a1-a2;
                    else if(t1=='*')
                        res=a1*a2;
                    else if(t1=='/')
                        res=a1/a2;
                    cout<<"res:"<<res<<endl;

                    s_number.push(res);
                    s_operator.push(t2);
                    break;
                }
                default:
                    cout<<"运算符错误"<<endl;
                    break;
                }
            }
        }
    }
    if(!s_number.empty()){
        res=s_number.top();
        s_number.pop();
    }
    return res;
}
int main()
{
    string s;
    cin>>s;

    //判断是否是第三种情况
    int i;
    int flag=0;
    for(i=0;i<s.length();i++){
        if(isVariable(s[i])){
            flag=1;
            break;
        }
    }
//    cout<<"flag:"<<flag<<endl;

    int res=-1;
    if(flag==0){    //第一、二种情况
        res=calculate(s);
        cout<<res<<endl;
    }
    else{   //第三种情况
        string s_sub;//子串，含x,y变量的
        i=0;
        while(i<s.length()&&s[i]!='|')
            i++;
        s_sub=s.substr(0,i);

        //假设只有两个变量，多变量需要回溯
        var vars[2]; //变量结构体数组
        int var_num=0;//变量个数

        //分离变量名，开始位置，结束位置，步长
        while(i<s.length()){
            //获取变量
            string st; //临时变量,记录每个变量
            while(i<s.length()&&s[i]!=':'){
                st+=s[i];
                i++;
            }
            i++; //跳过冒号

            //获取循环参数 开始，结束，步长 前闭后开
            int start,end,bc;
            start=s[i]-'0';
            i++;
            while(i<s.length()&&s[i]!=','){
                start=start*10+(s[i]-'0');
                i++;
            }
            i++; //跳过逗号

            end=s[i]-'0';
            i++;
            while(i<s.length()&&s[i]!=','){
                end=end*10+(s[i]-'0');
                i++;
            }
            i++;

            bc=s[i]-'0';
            i++;
            while(i<s.length()&&s[i]!=';'){
                bc=bc*10+(s[i]-'0');
                i++;
            }
            i++;

            //存入结构体数组
            vars[var_num]={st,start,end,bc};
            var_num++;
        }

        int k,l;
        for(k=vars[0].start;k<vars[0].end;k+=vars[0].bc){
            for(l=vars[1].start;l<vars[1].end;l+=vars[1].bc){
                //变量0用k代替，变量1用l代替
                int pos;
                pos = s_sub.find(vars[0].var_name);//查找指定的串
                while (pos != -1)
                {
                    char num_str[10];
                    sprintf(num_str,"%d",k);
                    s_sub.replace(pos,vars[0].var_name.length(),num_str);//用新的串替换掉指定的串
                    pos = s_sub.find(vars[0].var_name);//继续查找指定的串，直到所有的都找到为止
                }

                pos = s_sub.find(vars[1].var_name);//查找指定的串
                while (pos != -1)
                {
                    char num_str[10];
                    sprintf(num_str,"%d",l);
                    s_sub.replace(pos,vars[1].var_name.length(),num_str);//用新的串替换掉指定的串
                    pos = s_sub.find(vars[1].var_name);//继续查找指定的串，直到所有的都找到为止
                }

                res=calculate(s_sub);
                cout<<res<<endl;
            }
        }
    }

    return 0;
}
