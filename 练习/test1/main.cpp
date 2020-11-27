//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
#include<iostream>
#include<stack>
#include<string>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

using namespace std;
//typedef int Status;
//typedef char SElemType;
//typedef struct
//{//顺序栈的存储结构
//    SElemType *base;
//    SElemType *top;
//    int stacksize;
//}SqStack;
//Status InitStack(SqStack &S)
//{//初始化，构造一个空栈S
//    S.base=new SElemType[MAXSIZE];
//    if(!S.base) exit(OVERFLOW);
//    S.top=S.base;
//    S.stacksize=MAXSIZE;
//    return OK;
//}
//Status Push(SqStack &S,SElemType e)
//{//入栈
//    if(S.top-S.base==S.stacksize) return ERROR;
//    *S.top++=e;
//    return OK;
//}
//Status Pop(SqStack &S,SElemType &e)
//{//出栈，删除S的栈顶元素，用e返回其值
//    if(S.top==S.base)
//    return ERROR;
//    e=*--S.top;
//    return OK;
//}
//SElemType GetTop(SqStack S)
//{//取栈顶元素 ，返回S的栈顶元素，不修改栈顶指针
//    if(S.top!=S.base)
//    return *(S.top-1);
//}
//int In(SElemType c)
//{//判断c是否为运算符
//    switch(c)
//    {
//    case'+':return OK;
//    case'-':return OK;
//    case'*':return OK;
//    case'/':return OK;
//    case'(':return OK;
//    case')':return OK;
//    case'#':return OVERFLOW;
//    default:return ERROR;
//    }
//}
//SElemType Precede(SElemType t1,SElemType t2)
//{//判断运算符t1和t2的优先级
//    SElemType f;
//    switch(t2)
//    {
//    case'+':
//    case'-':if(t1=='('||t1=='#')
//                f='<';
//            else
//                f='>';
//            break;
//    case'*':if(t1=='*'||t1=='/'||t1==')')
//                f='>';
//            else
//                f='<';
//            break;
//    case'/':if(t1=='*'||t1=='/'||t1==')')
//                f='>';
//            else
//                f='<';
//            break;
//    case'(':f='<';
//    case')':if(t1=='(')
//                f='=';
//            else
//                f='>';
//            break;
//    case'#':if(t1=='#')
//                f='=';
//            else
//                f='>';
//    }
//    return f;
//}
//SElemType Operate(SElemType a,SElemType theta,SElemType b)
//{//对a和b进行二元运算theta
//    SElemType c;
//    a=a-48;
//    b=b-48;
//    switch(theta)
//    {
//    case'+':c=a+b+48;
//            break;
//    case'-':c=a-b+48;
//            break;
//    case'*':c=a*b+48;
//            break;
//    case'/':c=a/b+48;
//            break;
//    }
//    return c;
//}
//char EvaluateExpression()
//{//算术表达式求值，设OPTR和OPND分别为运算符栈和操作数栈
//    SqStack OPND,OPTR;
//    InitStack(OPND);
//    InitStack(OPTR);
//    char ch,a,b,theta,x;
//    Push(OPTR,'#');
//    cin>>ch;
//    while(ch!='#'||GetTop(OPTR)!='#')
//    {
//        if(!In(ch))
//        {
//            Push(OPND,ch);
//            cin>>ch;
//        }
//        else
//        {
//            switch(Precede(GetTop(OPTR),ch))
//            {
//                case '<':
//                    Push(OPTR,ch);
//                    cin>>ch;
//                    break;
//                case '>':
//                    Pop(OPTR,theta);
//                    Pop(OPND,b);
//                    Pop(OPND,a);
//                    Push(OPND,Operate(a,theta,b));
//                    break;
//                case '=':
//                    Pop(OPTR,x);
//                    cin>>ch;
//                    break;
//            }
//        }
//    }
//    return GetTop(OPND)-48;
//}
int main()
{
   cout<<"请输入算术表达式,并以#结束."<<endl;
//   cout<<EvaluateExpression()<<endl;
   return 0;
}
