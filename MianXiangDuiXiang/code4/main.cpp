#include <iostream>
#include <string>

using namespace std;

class Building{
    //这个函数可以访问这个类的私有成员；
    friend void goodgay(Building building);

public:
    string livingroom;
    Building(string livingroom,string bedroom){
        this->bedroom=bedroom;
        this->livingroom=livingroom;
    }

private:
    string bedroom;

};

void goodgay(Building building){
    cout<<"正在访问"<<building.livingroom<<endl;
    cout<<"正在访问"<<building.bedroom<<endl;
}
int main()
{
    Building building("客厅","卧室");
    goodgay(building);
    return 0;
}
