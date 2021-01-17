#include <iostream>

using namespace std;

//堆区的内存空间由程序员开辟和释放
int* func()
{
    int* a = new int(10);
    return a;
}

int main() {

    int *p = func();

    cout << p << endl;

    int *a = new int(5);
    cout << a << endl;

    system("pause");

    return 0;
}
