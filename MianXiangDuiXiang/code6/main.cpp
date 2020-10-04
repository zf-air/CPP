#include <iostream>
#include <string>
using namespace std;

class Building;
class Goodgay{
public:
    Goodgay();
    void visit();
    void visit2();
private:
    Building *building;
};

class Building{
    friend void Goodgay::visit();
public:
    Building();
    string livingroom;

private:
    string bedroom;
};


Building::Building(){
    livingroom="客厅";
    bedroom="卧室";
}
Goodgay::Goodgay(){
    building=new Building();
}

void Goodgay::visit(){
    cout<<"visit:"<<building->livingroom<<endl;
    cout<<"visit:"<<building->bedroom<<endl;
}
void Goodgay::visit2(){
    cout<<"visit:"<<building->livingroom<<endl;
}
void test(){
    Goodgay gg;
    gg.visit();
    gg.visit2();
}
int main()
{
    test();
    return 0;
}
