#include <iostream>

using namespace std;

class Base{
public:
    int a;
protected:
    int b;
private:
    int c;
};

//父类私有成员子类都不能访问
class Son:public Base{
    void fun(){
        a=10;
        b=10;

        //c=10;
    }
};

class Son3:private Base{
public:
    void fun(){
        a=20;
        b=20;
        cout<<"a:"<<a<<" b:"<<b<<endl;
    }
};

class Grandson:public Son3{

    //a=30;

};

int main()
{
    Grandson gs;
    gs.fun();
    return 0;
}
