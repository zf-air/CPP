#include <iostream>

using namespace std;

int main() {

    int a = 10;
    int b = 20;
    //int &c; //错误，引用必须初始化
    int &c = a; //一旦初始化后，就不可以更改
    c = b; //这是赋值操作，不是更改引用
    //把c指向位置的内容更改为b的内容，a和c始终都指向同一个地方

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    /*
    a = 20
    b = 20
    c = 20
    */

    cout<<"a的地址："<<&a<<endl;
    cout<<"c的地址："<<&c<<endl;
    /*
    a的地址：0x61fe0c
    c的地址：0x61fe0c
    */

    system("pause");

    return 0;
}
