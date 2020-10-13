#include <iostream>
#include <stack>
#include <string>

//用于调试程序,需要的话写上，不需要的话加上注释，就不会产生中间结果
#define debug

//如果不用debug的话就像下面这样
//#define debug

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

//传入操作符栈，数据栈和操作符栈的栈顶符号t1
void calculate_twonums(stack<char> &s_operator,stack<int> &s_number,char t1){
    //操作符退栈并将运算结果压入s_number中
    s_operator.pop();

    //获取两个操作数,注意取的顺序，后进先出
    int a2=s_number.top();
    s_number.pop();
    int a1=s_number.top();
    s_number.pop();

#ifdef debug
    cout<<"a1:"<<a1<<" a2:"<<a2<<endl;
#endif

    //a1 t1 a2,进行运算
    int t=0;
    if(t1=='+')
        t=a1+a2;
    else if(t1=='-')
        t=a1-a2;
    else if(t1=='*')
        t=a1*a2;
    else if(t1=='/')
        t=a1/a2;

#ifdef debug
    cout<<"t:"<<t<<endl;
#endif

    //结果入栈
    s_number.push(t);

}
int calculate(string s){
    //运算符栈
    stack<char> s_operator;
    //数字栈
    stack<int> s_number;
    int length=(int)s.length();  //原始字符串长度

#ifdef debug
    cout<<"length:"<<length<<endl;
#endif

    int i=0;    //字符串的下标，可以看做指针
    int res=-1; //结果变量

    //遍历字符串,获取每个字符(char)
    while(i<length){

        //如果是数字
        if(isNumber(s[i])){
            int num=s[i]-'0';   //s[i]是char类型，需要-'0',得到int型的数字
            i++;
            //数字可能有多位，比如123
            while(i<length&&isNumber(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            s_number.push(num);
        }

        //如果是运算符
        else if(isOperator(s[i])){
            //符号栈为空，直接入栈
            if(s_operator.empty()){
                s_operator.push(s[i]);
                i++;
                continue;
            }
            //符号栈不为空
            else{
                char t1,t2;
                t1=s_operator.top(); //上一个操作符
                t2=s[i];  //现在的操作符

#ifdef debug
                cout<<"t1:"<<t1<<endl;
                cout<<"t2:"<<t2<<endl;
#endif

                switch(Precede(t1, t2))
                {
                case '<':   //当前已经压栈一个运算符（t1）比后一个运算符（t2）低时，就将t2压栈
#ifdef debug
                    cout<<"优先级: <"<<endl;
#endif
                    s_operator.push(t2);
                    i++;
                    break;
                case '=':
#ifdef debug
                    cout<<"优先级: ="<<endl;
#endif
                    s_operator.pop();   //脱括号
                    i++;
                    break;
                case '>':
                {
#ifdef debug
                    cout<<"优先级: >"<<endl;
#endif
                    //调用计算a1 t1 a2的函数
                    calculate_twonums(s_operator,s_number,t1);
                    break;
                }
                default:
                    cout<<"运算符错误"<<endl;
                    return -1;
                }
            }
        }
    }
    //符号栈不空,继续进行后面的操作,从后往前读就行
    while(!s_operator.empty()&&!s_number.empty()){
        char t1;
        t1=s_operator.top();
        calculate_twonums(s_operator,s_number,t1);
    }
    //最后留一个数字在数字栈，是最终结果
    if(s_number.size()==1){
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
        if(isVariable(s[i])){   //判断条件函数
            flag=1;
            break;
        }
    }

    int res=-1;
    if(flag==0){    //第一、二种情况
#ifdef debug
        cout<<"情况1,2"<<endl;
#endif
        res=calculate(s);
        cout<<"result:"<<res<<endl;
    }
    else{   //第三种情况
#ifdef debug
        cout<<"情况3"<<endl;
#endif
        string s_sub;//子串，含x,y变量的
        i=0;
        while(i<s.length()&&s[i]!='|')
            i++;
        s_sub=s.substr(0,i);
        i++;//跳过 |

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
            //开始
            start=s[i]-'0';
            i++;
            //获取全部数字
            while(i<s.length()&&s[i]!=','){
                start=start*10+(s[i]-'0');
                i++;
            }
            i++; //跳过逗号

            //结束
            end=s[i]-'0';
            i++;
            while(i<s.length()&&s[i]!=','){
                end=end*10+(s[i]-'0');
                i++;
            }
            i++;

            //步长
            bc=s[i]-'0';
            i++;
            while(i<s.length()&&s[i]!=';'){
                bc=bc*10+(s[i]-'0');
                i++;
            }
            if(i<s.length())
                i++;

            //存入结构体数组
            vars[var_num]={st,start,end,bc};
            var_num++;
        }

#ifdef debug
        //打印结构体内容
        for(int k=0;k<2;k++){
            cout<<"var_name:"<<vars[k].var_name<<" start:"<<vars[k].start<<
                  " end:"<<vars[k].end<<" bc:"<<vars[k].bc<<endl;
        }
#endif

        //循环，寻找变量名并替换为对应的数字
        int k,l;
        for(k=vars[0].start;k<vars[0].end;k+=vars[0].bc){
            for(l=vars[1].start;l<vars[1].end;l+=vars[1].bc){
                //复制字符串
                string ss=s_sub;

                //变量0的name用数字k代替，变量1的name用数字l代替
                int pos;
                pos = ss.find(vars[0].var_name); //查找指定的串,返回第一次出现的位置
                //循环查找所有的，并替换
                while (pos != -1)
                {
                    //用来替换的字符数组，存放数字
                    char num_str[10];
                    //数字转字符串
                    sprintf(num_str,"%d",k);
                    //用新的串替换掉指定的串
                    ss.replace(pos,vars[0].var_name.length(),num_str);
                    //继续查找指定的串，直到所有的都找到为止
                    pos = ss.find(vars[0].var_name);
                }

                pos = ss.find(vars[1].var_name);//查找指定的串
                while (pos != -1)
                {
                    char num_str[10];
                    sprintf(num_str,"%d",l);
                    ss.replace(pos,vars[1].var_name.length(),num_str);//用新的串替换掉指定的串
                    pos = ss.find(vars[1].var_name);//继续查找指定的串，直到所有的都找到为止
                }
#ifdef debug
                //输出替换后的字符串
                cout<<"ss:"<<ss<<endl;
#endif
                res=calculate(ss); //进行计算
                cout<<"result:"<<res<<endl;
            }
        }
    }

    return 0;
}
