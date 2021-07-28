#include <iostream>
#include "defineList.h"
#include "operator.h"
using namespace std;

int main() {
    //初始化
    Sqlist L;
    Operator ope;
    ope.initList(L);
    cout<<"我爱你"<<endl;
    //插入数据
    ope.insertList(L,1,5);
    ope.insertList(L,2,3);
    ope.insertList(L,1,7);

    //打印列表
    ope.printList(L);

    //删除数据
    ElemType e;
    ope.deleteList(L,2,e);
    cout<<"删除了"<<e<<endl;
    ope.printList(L);

    //销毁列表
    ope.destroyList(L);
    return 0;
}
