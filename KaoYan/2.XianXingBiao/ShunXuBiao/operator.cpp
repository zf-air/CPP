//
// Created by Hi! J.Smith on 2021/7/28.
//

#include "defineList.h"
#include "operator.h"

//初始化
void Operator::initList(Sqlist &L) {
    L.data = new ElemType[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
    return;
}

//插入元素
bool Operator::insertList(Sqlist &L, int i, ElemType e) {
    //判断是否越界
    if (i <= 0 || i > L.length + 1)
        return false;
    //判断是否还有位置
    if (L.length == L.MaxSize)
        return false;
    //往右移
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    //添加
    L.data[i - 1] = e;
    //长度加一
    L.length++;
    return true;
}

//删除元素
bool Operator::deleteList(Sqlist &L, int i, ElemType &e) {
    //判断是否越界
    if (i <= 0 || i > L.length)
        return false;
    //判断是否为空
    if (L.length == 0)
        return false;
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length - 1; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

//查找元素
int Operator::locateList(Sqlist L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            cout << "查找到元素" << e << ",在第" << i << "个位置" << endl;
            return i;
        }
    }
    cout << "未查找到元素" << e << endl;
    return -1;
}

//打印所有元素
void Operator::printList(Sqlist &L) {
    cout << "[";
    for (int i = 0; i < L.length; i++) {
        if (i == L.length - 1) {
            cout << L.data[i];
        } else {
            cout << L.data[i] << ",";
        }
    }
    cout << "]" << endl;
    return;
}

//销毁列表
void Operator::destroyList(Sqlist &L) {
    delete[] L.data;
}