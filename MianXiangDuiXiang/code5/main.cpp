#include <iostream>
#include <string>
using namespace std;

class Building{
    //声明友元类，可以访问该类的私有成员
    friend class Goodgay;

public:
    string livingroom;
    Building(string livingroom,string bedroom);

private:
    string bedroom;
};

class Goodgay{
public:
    Goodgay();
    void visit();
private:
    Building *building;
};

//类外实现函数
Building::Building(string livingroom,string bedroom){
    this->bedroom=bedroom;
    this->livingroom=livingroom;
}

Goodgay::Goodgay(){
    building = new Building("客厅","卧室");
}

void Goodgay::visit(){
    cout<<"visit:"<<building->livingroom<<endl;
    cout<<"visit:"<<building->bedroom<<endl;
}
void test(){
    Goodgay goodgay;
    goodgay.visit();
}
int main()
{
    test();
    return 0;
}
