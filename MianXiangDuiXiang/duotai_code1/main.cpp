#include <iostream>

using namespace std;
class Calculator{
public:
    virtual int calcute(){
        return 0;
    }
    int a;
    int b;
};

class Addcaculator:public Calculator{
    int calcute(){
        return a+b;
    }
};
class Subcaculator:public Calculator{
    int calcute(){
        return a-b;
    }
};
class Mulcaculator:public Calculator{
    int calcute(){
        return a*b;
    }
};
class Divcaculator:public Calculator{
    int calcute(){
        return a/b;
    }
};

int calcute(Calculator &cal){
    int res=cal.calcute();
    return res;
}
int main()
{
    Addcaculator add;
    Subcaculator sub;
    Mulcaculator mul;
    Divcaculator div;
    add.a=10;
    add.b=10;
//    Calculator* cal=&add;
    cout<<"加法:"<<calcute(add)<<endl;

}
