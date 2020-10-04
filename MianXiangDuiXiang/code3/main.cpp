
#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    string name;
    int age;
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    //返回对象
    Person addAge(Person p){
        this->age+=p.age;
        return *this;
    }
    //引用返回
    Person& addAge2(Person p){
        this->age+=p.age;
        return *this;
    }
};


int main()
{
    Person p1("zhangfan",5);

    Person p2("zhangsan",10);

    p2.addAge(p1).addAge(p1);
    cout<<p2.age<<endl;

    p2.addAge2(p1).addAge2(p1);
    cout<<p2.age<<endl;
    return 0;
}
