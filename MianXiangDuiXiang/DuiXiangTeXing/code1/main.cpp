#include <iostream>

using namespace std;

class Person{
public:
    Person(){
        cout<<"Person的无参构造函数"<<endl;
    }
    Person(int a){
        age=a;
        cout<<"Person的有参构造函数"<<endl;
    }

    //拷贝构造函数
    Person(const Person &p){
        age=p.age;
        cout<<"Person的拷贝构造函数"<<endl;
    }

    ~Person(){
        cout<<"Person的析构函数"<<endl;
    }
private:
    int age;
};

void test(){
    Person p;
    Person p1(10);
    Person p2(p1);

}
int main()
{
    test();

    return 0;
}
