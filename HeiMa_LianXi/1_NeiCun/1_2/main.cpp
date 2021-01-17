#include <iostream>

using namespace std;

//不能这样返回,栈区的内存空间随着函数关闭而释放
int * func()
{
    int a = 10;
    return &a;
}

int main() {

    int *p = func();

    cout << *p << endl;
    cout << *p << endl;

    system("pause");

    return 0;
}
