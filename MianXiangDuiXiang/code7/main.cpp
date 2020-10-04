#include <iostream>
#include <string>

using namespace std;

class Person{
public:

    // 成员函数 +号重载
//    Person operator+(Person p){
//        Person temp;
//        temp.m_a=p.m_a+this->m_a;
//        temp.m_b=p.m_b+this->m_b;
//        return temp;
//    }

    int m_a;
    int m_b;

};

//全局函数 加号重载
Person operator+(Person p1,Person p2){
    Person temp;
    temp.m_a=p1.m_a+p2.m_a;
    temp.m_b=p1.m_b+p2.m_b;
    return temp;
}
//函数重载,参数必须为两个
Person operator+(Person p,int a){
    Person temp;
    temp.m_a=p.m_a+a;
    temp.m_b=p.m_b+a;
    return temp;
}

void test(){
    Person p1;
    p1.m_a=10;
    p1.m_b=10;
    Person p2;
    p2.m_a=10;
    p2.m_b=10;

    Person p3;
    p3=p1+p2;
    cout<<"p3 m_a:"<<p3.m_a<<endl;
    cout<<"p3 m_b:"<<p3.m_b<<endl;

    Person p4;
    p4=p1+p2;
    cout<<"p4 m_a:"<<p4.m_a<<endl;
    cout<<"p4 m_b:"<<p4.m_b<<endl;
}
int main()
{
    test();

    return 0;
}
