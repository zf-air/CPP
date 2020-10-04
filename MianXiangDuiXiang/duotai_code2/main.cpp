#include <iostream>
// 案例2 冲咖啡和茶叶
using namespace std;

class Abstractdrinking{
public:
    //抽象类
    virtual void putwater()=0;
    virtual void putsomething()=0;
    virtual void putcup()=0;
    virtual void drink()=0;

    void dowork(){
        putwater();
        putsomething();
        putcup();
        drink();
    }
};

class Coffee:public Abstractdrinking{
public:
    void putwater(){
        cout<<"咖啡加水"<<endl;
    }
    void putsomething(){
        cout<<"加咖啡"<<endl;
    }
    void putcup(){
        cout<<"咖啡倒入杯中"<<endl;
    }
    void drink(){
        cout<<"喝咖啡"<<endl;
    }
};

class Tea:public Abstractdrinking{
public:
    void putwater(){
        cout<<"茶加水"<<endl;
    }
    void putsomething(){
        cout<<"加茶"<<endl;
    }
    void putcup(){
        cout<<"茶倒入杯中"<<endl;
    }
    void drink(){
        cout<<"喝茶"<<endl;
    }
};

void test(Abstractdrinking &drink){
    drink.dowork();
}
void test(Abstractdrinking* drink){
    drink->dowork();
}
int main()
{
    Coffee coffee;
    test(coffee);
    cout<<"--------"<<endl;
    Tea tea;
    test(tea);
    cout<<"---------------"<<endl;
    test(new Coffee);
    cout<<"--------"<<endl;
    test(new Tea);
    return 0;
}
