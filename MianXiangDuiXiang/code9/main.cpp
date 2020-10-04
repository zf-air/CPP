#include <iostream>

using namespace std;

class MyInteger{

    friend ostream& operator<<(ostream& cout,MyInteger myint);
public:
    MyInteger(){
        num=0;
    }
    //前置++重载
    MyInteger& operator++(){
        num++;
        return *this;
    }

    //后置++重载
    MyInteger operator++(int){
        MyInteger temp=*this;
        this->num++;
        return temp;
    }
private:
    int num;
};

ostream& operator<<(ostream& cout,MyInteger myint){
    cout<<myint.num;
    return cout;
}

void test(){
    MyInteger myint;
    cout<<++myint<<endl;
    cout<<myint++<<endl;
    cout<<myint<<endl;
}
int main()
{
    test();
    return 0;
}
