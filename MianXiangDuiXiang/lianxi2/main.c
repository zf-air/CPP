#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//用于调试程序,需要的话写上，不需要的话加上注释，就不会产生中间结果
#define debug

//如果不用debug的话就像下面这样
//#define debug
// 栈结构的定义

typedef struct _stack
{
    int size;   // 栈存储空间的尺寸
    int* base;   // 栈基址
    int* sp;    // 栈顶
} stack;

//变量结构体
struct var{
    char* var_name;//变量名
    int start;//开始位置
    int end;//结束位置
    int bc;//步长
}vars[2];

void init(stack* s, int n)
{
    s->base = (int*)malloc(sizeof(int)*n);
    s->size = n;
    s->sp = s->base;
}

void push(stack* s, int val)
{
    if(s->sp - s->base == s->size)
    {
        puts("none");
        exit(1);
    }
    *s->sp++ = val;
}

int pop(stack* s)
{
    if(s->sp == s->base)
    {
        puts("none");
        exit(2);
    }
    return *--s->sp;
}
int top(stack*s)
{
    if(s->sp == s->base)
    {
        puts("none");
        exit(2);
    }

    return *(s->sp-1);
}

int empty(stack* s)
{
    return s->sp == s->base;
}

int size(stack* s)
{
    return s->sp-s->base;
}

void clean(stack* s)
{
    if(s->base)
        free(s->base);
}

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
void calculate_twonums(stack* s_operator,stack* s_number,char t1){
    //操作符退栈并将运算结果压入s_number中
    pop(s_operator);

    //获取两个操作数,注意取的顺序，后进先出
    int a2=top(s_number);
    pop(s_number);
    int a1=top(s_number);
    pop(s_number);

#ifdef debug
    printf("a1:%d a2:%d",a1,a2);
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
    printf("t:%d",t);
#endif

    //结果入栈
    push(s_number,t);

}

int calculate(char* s){
    //运算符栈，并初始化
    stack* s_operator;
    init(s_operator,100);
    //数字栈
    stack* s_number;
    init(s_number,100);
    int length=strlen(s);  //原始字符串长度

#ifdef debug
    printf("length:%d",length);
#endif

//    int i=0;    //字符串的下标，可以看做指针
//    int res=-1; //结果变量
//
//    //遍历字符串,获取每个字符(char)
//    while(i<length){
//
//        //如果是数字
//        if(isNumber(s[i])){
//            int num=s[i]-'0';   //s[i]是char类型，需要-'0',得到int型的数字
//            i++;
//            //数字可能有多位，比如123
//            while(i<length&&isNumber(s[i])){
//                num=num*10+(s[i]-'0');
//                i++;
//            }
//            push(s_number,num);
//        }
//
//        //如果是运算符
//        else if(isOperator(s[i])){
//            //符号栈为空，直接入栈
//            if(empty(s_operator)){
//                push(s_operator,s[i]);
//                i++;
//                continue;
//            }
//            //符号栈不为空
//            else{
//                char t1,t2;
//                t1=top(s_operator); //上一个操作符
//                t2=s[i];  //现在的操作符
//
//#ifdef debug
//                printf("t1:%d",t1);
//                printf("t2:%d",t2);
//#endif
//
//                switch(Precede(t1, t2))
//                {
//                case '<':   //当前已经压栈一个运算符（t1）比后一个运算符（t2）低时，就将t2压栈
//#ifdef debug
//                    printf("优先级：>");
//#endif
//                    push(s_operator,t2);
//                    i++;
//                    break;
//                case '=':
//#ifdef debug
//                    printf("优先级：=");
//#endif
//                    pop(s_operator);   //脱括号
//                    i++;
//                    break;
//                case '>':
//                {
//#ifdef debug
//                    printf("优先级：>");
//#endif
//                    //调用计算a1 t1 a2的函数
//                    calculate_twonums(s_operator,s_number,t1);
//                    break;
//                }
//                default:
//                    printf("运算符错误");
//                    return -1;
//                }
//            }
//        }
//    }
//    //符号栈不空,继续进行后面的操作,从后往前读就行
//    while(!empty(s_operator)&&!empty(s_number)){
//        char t1;
//        t1=top(s_operator);
//        calculate_twonums(s_operator,s_number,t1);
//    }
//    //最后留一个数字在数字栈，是最终结果
//    if(size(s_number)==1){
//        res=top(s_number);
//        pop(s_number);
//    }
    return res;
}

//指定字符串替换源字符串
void replace(char* ss,char* pos,int length,char* num_str){
    char* st;
    int s=pos-ss;
    int i=s,j=0;
    for(j=0;j<s;j++){
        st[j]=ss[j];
    }
    for(j=s;j<s+strlen(num_str);j++){
        st[j]=num_str[j-s];
    }
    for(j=s+strlen(num_str);j<s+strlen(num_str)+strlen(ss)-s-length;j++){
        st[j]=ss[j-strlen(num_str)+length];
    }
    strcpy(ss,st);
}

int main(){
    char* s=(char *)malloc(sizeof(char)*100);
    scanf("%s",s);
#ifdef debug
    printf("%s\n",s);
#endif
    //判断是否是第三种情况
    int i;
    int flag=0;
    int length=strlen(s);
    for(i=0;i<length;i++){
        if(isVariable(s[i])){   //判断条件函数
            flag=1;
            break;
        }
    }

    int res=-1;
    if(flag==0){    //第一、二种情况
#ifdef debug
        printf("情况1,2\n");
#endif
        res=calculate(s);
        printf("res:%d\n",res);
    }
    else{   //第三种情况
#ifdef debug
        printf("情况3\n");
#endif
        char* s_sub;//子串，含x,y变量的
        i=0;
        while(i<length&&s[i]!='|')
            i++;
//        s_sub=s.substr(0,i);
        strncpy(s_sub,s,i);
        i++;//跳过 |

        //假设只有两个变量，多变量需要回溯
//        var vars[2]; //变量结构体数组
        int var_num=0;//变量个数

        //分离变量名，开始位置，结束位置，步长
        while(i<length){
            //获取变量
            char* st; //临时变量,记录每个变量
            while(i<length&&s[i]!=':'){
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
            while(i<length&&s[i]!=','){
                start=start*10+(s[i]-'0');
                i++;
            }
            i++; //跳过逗号

            //结束
            end=s[i]-'0';
            i++;
            while(i<length&&s[i]!=','){
                end=end*10+(s[i]-'0');
                i++;
            }
            i++;

            //步长
            bc=s[i]-'0';
            i++;
            while(i<length&&s[i]!=';'){
                bc=bc*10+(s[i]-'0');
                i++;
            }
            if(i<length)
                i++;

            //存入结构体数组
//            vars[var_num]={st,start,end,bc};
            strcpy(vars[var_num].var_name,st);
            vars[var_num].start=start;
            vars[var_num].end=end;
            vars[var_num].bc=bc;
            var_num++;
        }

#ifdef debug
        //打印结构体内容
        int a=0;
        for(a=0;a<2;a++){
            printf("var_name:%s start:%s end:%s bc:%s\n",vars[a].var_name,
                        vars[a].start,vars[a].end,vars[a].bc);
        }
#endif

        //循环，寻找变量名并替换为对应的数字
        int k,l;
        for(k=vars[0].start;k<vars[0].end;k+=vars[0].bc){
            for(l=vars[1].start;l<vars[1].end;l+=vars[1].bc){
                //复制字符串
                char* ss;
                strcpy(ss,s_sub);

                //变量0的name用数字k代替，变量1的name用数字l代替
                char* pos;
                pos = strchr(ss,vars[0].var_name); //查找指定的串,返回第一次出现的位置
                //循环查找所有的，并替换
                while (pos != NULL)
                {
                    //用来替换的字符数组，存放数字
                    char num_str[10];
                    //数字转字符串
                    sprintf(num_str,"%d",k);
                    //用新的串替换掉指定的串
                    replace(ss,pos,strlen(vars[0].var_name),num_str);
                    //继续查找指定的串，直到所有的都找到为止
                    pos = strchr(ss,vars[0].var_name);
                }

                pos = strchr(ss,vars[1].var_name);//查找指定的串
                while (pos != NULL)
                {
                    char num_str[10];
                    sprintf(num_str,"%d",l);
                    replace(ss,pos,strlen(vars[1].var_name),num_str);//用新的串替换掉指定的串
                    pos = strchr(ss,vars[1].var_name);//继续查找指定的串，直到所有的都找到为止
                }
#ifdef debug
                //输出替换后的字符串
                printf("ss:%s",ss);
#endif
                res=calculate(ss); //进行计算
                printf("result:%d",res);
            }
        }
    }
    printf("hello");
    return 0;
}
