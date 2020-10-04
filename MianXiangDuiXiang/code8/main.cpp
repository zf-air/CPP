#include <iostream>
#include <string>
using namespace std;

class Person{
    friend ostream& operator<<(ostream& cout,Person p);
public:
    Person(int a,int b){
        this->a=a;
        this->b=b;
    }
private:
    int a;
    int b;
};

ostream& operator<<(ostream& cout,Person p){
    cout<<"p.a:"<<p.a<<" p.b:"<<p.b<<endl;
    return cout;
}
void test(){
    Person p(10,10);
    cout<<p<<"hello"<<endl;
}
int main()
{
    test();
    return 0;
}
