#include <iostream>

using namespace std;
class Base{
public:
    int a=5;

    static void fun(){
        cout<<"base"<<endl;
    }
    void fun(int a){
        cout<<"base a"<<a<<endl;
    }
};

class Son:public Base{
public:
    int a=10;

    static void fun(){
        cout<<"son"<<endl;
    }
};

void test1(){
    Son s;
    s.fun();
    cout<<s.a<<endl;

    s.Base::fun();
    cout<<s.Base::a<<endl;
}

//通过类名调用 静态成员
void test2(){
    Son::fun();

    Son::Base::fun();
}
int main()
{
//    test1();
    test2();
    return 0;
}
