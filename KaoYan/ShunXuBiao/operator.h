//
// Created by Hi! J.Smith on 2021/7/28.
//

#ifndef SHUNXUBIAO_OPERATOR_H
#define SHUNXUBIAO_OPERATOR_H

#include "iostream"

using namespace std;

class Operator {
public:
    void initList(Sqlist &L);

    bool insertList(Sqlist &L, int, ElemType e);

    void printList(Sqlist &L);

    bool deleteList(Sqlist &L, int i, ElemType &e);

    void destroyList(Sqlist &L);
};

#endif //SHUNXUBIAO_OPERATOR_H
