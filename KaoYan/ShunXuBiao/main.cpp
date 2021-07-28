#include <iostream>
#include "defineList.h"
#include "operator.h"

using namespace std;

int main() {
    //初始化
    Sqlist L;
    Operator ope;
    ope.initList(L);

    //插入数据
    ope.insertList(L, 1, 5);
    ope.insertList(L, 2, 3);
    ope.insertList(L, 1, 7);

    //打印列表
    ope.printList(L);

    //查找元素
    int site;
    site = ope.locateList(L, 5);

    //删除数据
    ElemType e;
    ope.deleteList(L, 2, e);
    cout << "删除了元素" << e << endl;
    ope.printList(L);

    //查找元素
    site = ope.locateList(L, 5);

    //销毁列表
    ope.destroyList(L);
    return 0;
}
