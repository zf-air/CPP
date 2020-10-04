#include <iostream>

using namespace std;
class Base{
public:
    int a=5;

    void fun(){
        cout<<"base"<<endl;
    }
    void fun(int a){
        cout<<"base a"<<a<<endl;
    }
};

class Son:public Base{
public:
    int a=10;

    void fun(){
        cout<<"son"<<endl;
    }
};

void test(){
    Son s;
    s.fun();
    cout<<s.a<<endl;

    s.Base::fun(15);
    cout<<s.Base::a<<endl;
}
int main()
{
    test();
    return 0;
}
