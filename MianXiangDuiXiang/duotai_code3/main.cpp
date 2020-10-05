#include <iostream>
#include <string>
using namespace std;
class Animal{
public:

    Animal(){
        cout<<"Animal构造函数"<<endl;
    }

//    ~Animal(){
//        cout<<"Animal析构函数"<<endl;
//    }
    //当子类中含有指针时，不会调用子类的析构函数，所以要把父类的析构函数变为虚函数或者纯虚函数

    //虚析构函数,调用虚函数的同时也调用子类的析构函数
//    virtual ~Animal(){
//        cout<<"Animal虚析构函数"<<endl;
//    }

    //纯虚析构函数
    virtual ~Animal()=0;

    //纯虚函数
    virtual void speak()=0;
};
//类内声明，类外实现
Animal::~Animal(){
    cout<<"Animal纯虚析构函数"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"cat构造函数"<<endl;
        this->name=new string(name);
    }

    ~Cat(){
        cout<<"Cat析构函数"<<endl;
        delete name;
        name=NULL;
    }

    void speak(){
        cout<<*name<<"叫"<<endl;
    }
    string* name;
};

void test(){
    Animal* animal=new Cat("tom");
    animal->speak();
    delete animal;
}
int main()
{
    test();
    return 0;
}
