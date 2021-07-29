#include <iostream>

using namespace std;

#define ElemType int
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool initList(DLinkList &L) {
    cout << "尾插法创建双链表" << endl;
    DNode *r;
    L = new DNode;
    L->prior = nullptr;
    L->next = nullptr;
    r = L;
    int x;
    cout << "请输入";
    cin >> x;
    while (x != 9999) {
        DNode *s;
        s = new DNode;
        s->data = x;
        s->prior = r;
        s->next = nullptr;
        r->next = s;
        r = s;
        cout << "请输入";
        cin >> x;
    }
    return true;
}

//从前往后遍历
bool backPrintList(DLinkList L) {
    cout << "从前往后遍历" << endl;
    DNode *p = L->next;
    cout << "[";
    while (p) {
        cout << p->data;
        if (p->next)
            cout << ",";
        else
            cout << "]" << endl;
        p = p->next;
    }
    return true;
}

bool frontPrintList(DLinkList L) {
    cout << "从后往前遍历" << endl;
    DNode *p = L->next;
    DNode *r;
    while (p) {
        r = p;
        p = p->next;
    }
    cout << "[";
    while (r != L) {
        cout << r->data;
        if (r->prior != L)
            cout << ",";
        else
            cout << "]" << endl;
        r = r->prior;
    }
    return true;
}

//销毁链表
bool destroyList(DLinkList &L) {
    cout << "销毁链表" << endl;
    DNode *p = L;
    DNode *s;
    while (p) {
        s = p->next;
        delete p;
        p = s;
    }
    return true;
}

int main() {
    DLinkList L;
    initList(L);
    backPrintList(L);
    frontPrintList(L);
    destroyList(L);

    return 0;
}
