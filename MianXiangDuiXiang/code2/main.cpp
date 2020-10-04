#include <iostream>
#include <string>
using namespace std;

class Phone{
public:
    string pname;
    Phone(string pname){
        this->pname=pname;
        cout<<"Phone的构造函数"<<endl;
    }
    ~Phone(){
        cout<<"Phone的析构函数"<<endl;
    }
};

class Person{
public:
    string myname;
    Phone p;

    Person(string name,string pname):myname(name),p(pname){
        cout<<"Person构造函数"<<endl;
    }
    ~Person(){
        cout<<"Person的析构函数"<<endl;
    }
};

void test(){
    Person person("zhangfan","iphone xsmax");
    cout<<person.p.pname<<endl;
}
int main()
{
    test();
    return 0;
}
