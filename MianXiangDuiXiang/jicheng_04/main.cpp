#include <iostream>

using namespace std;
class Animal{
public:
    int age;
};

//虚继承解决菱形继承问题,继承的是指针,指向对应变量
class Dog:virtual public Animal{

};

class Cat:virtual public Animal{

};

class Son:public Dog,public Cat{

};

void test(){
    Son s;
    s.Cat::age=10;
    s.Dog::age=15;
    cout<<s.Cat::age<<endl;
    cout<<s.Dog::age<<endl;
    cout<<s.age<<endl; //都打印15
}
int main()
{
    test();
    return 0;
}
