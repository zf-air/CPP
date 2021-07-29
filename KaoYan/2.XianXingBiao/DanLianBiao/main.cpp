#include <iostream>

using namespace std;

#define ElemType int
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//头插法建立单链表
bool List_HeadInsert(LinkList &L) {
    cout << "---头插法建立单链表---" << endl;
    LNode *s;
    int x;
    L = new LNode;
    L->next = nullptr;
    cout << "请输入:";
    cin >> x;
    //9999作为结束
    while (x != 9999) {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cout << "请输入:";
        cin >> x;
    }
    return true;
}

//尾插法建立单链表
bool List_TailInsert(LinkList &L) {
    cout << "---尾插法建立单链表---" << endl;
    LNode *s, *r;
    int x;
    L = new LNode;
    L->next = nullptr;
    r = L;
    cout << "请输入:";
    cin >> x;
    while (x != 9999) {
        s = new LNode;
        s->data = x;
        s->next = nullptr;
        r->next = s;
        r = r->next;
        cout << "请输入:";
        cin >> x;
    }
    return true;
}

//单链表原地逆置
bool reverseList(LinkList &L) {
    cout << "链表就地逆置" << endl;
    LNode *p, *pre, *next;
    pre = nullptr;
    p = L->next;
    if (p == nullptr)
        return true;
    next = p->next;
    while (p) {
        p->next = pre;
        pre = p;
        p = next;
        if (p)
            next = p->next;
    }
    L->next = pre;
    return true;
}

//按序号查找节点值
LNode *GetElem(LinkList L, int i) {
    cout << "---按序号查找---" << endl;
    LNode *p = L->next;
    int j = 1;
    if (i == 0) {
        return L;
    }
    if (i < 1) {
        return nullptr;
    }
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找节点值
LNode *LocateElem(LinkList L, ElemType e) {
    cout << "---按值查找---" << endl;
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//插入节点,插入到第i个位置上
bool insertElem(LinkList &L, int i, ElemType e) {
    cout << "---插入节点---" << endl;
    LNode *p;
    p = GetElem(L, i - 1);
    if (p == nullptr) {
        return false;
    } else {
        LNode *s = new LNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
    }
    return true;
}

//删除节点
bool deleteElem(LinkList &L, int i) {
    cout << "---删除节点---" << endl;
    if (i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    if (p == nullptr) {
        return false;
    } else {
        if (p->next == nullptr)
            return false;
        LNode *s = p->next;
        p->next = s->next;
        delete s;
    }
    return true;
}

//获取链表长度
int GetLength(LinkList L) {
    cout << "---获取链表长度---" << endl;
    int cnt = 0;
    LNode *p = L->next;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

//打印链表
bool printList(LinkList L) {
    cout << "---打印链表---" << endl;
    LNode *p;
    p = L->next;
    cout << "[";
    while (p) {
        cout << p->data;
        if (p->next) {
            cout << ",";
        } else {
            cout << "]" << endl;
        }
        p = p->next;
    }
}

//销毁链表
bool destroyList(LinkList &L) {
    cout << "---销毁链表---" << endl;
    LNode *p, *s;
    p = L;
    while (p) {
        s = p->next;
        delete p;
        p = s;
    }
    return true;
}

int main() {
    LinkList L;

    //头插法
    /*List_HeadInsert(L);
    printList(L);
    destroyList(L);*/

    //尾插法
    /*List_TailInsert(L);
    printList(L);
    destroyList(L);*/

    //链表就地逆置
    List_HeadInsert(L);
    printList(L);
    reverseList(L);
    printList(L);
    destroyList(L);

    //按序号查找
    /*List_TailInsert(L);
    printList(L);
    LNode *p = GetElem(L, 4);
    if (p) {
        cout << "查找到的元素为" << p->data << endl;
    } else {
        cout << "未查找到" << endl;
    }
    destroyList(L);*/

    //按序号查找
    /*List_TailInsert(L);
    printList(L);
    LNode *p = LocateElem(L, 2);
    if (p) {
        cout << "查找到的元素为" << p->data << endl;
    } else {
        cout << "未查找到" << endl;
    }
    destroyList(L);*/

    //插入节点
    /*List_TailInsert(L);
    printList(L);
    insertElem(L, 3, 888);
    printList(L);
    destroyList(L);*/

    //删除节点
    /*List_TailInsert(L);
    printList(L);
    bool tag = deleteElem(L, 1);
    if (tag)
        cout << "删除成功" << endl;
    else
        cout << "删除失败" << endl;
    printList(L);
    destroyList(L);*/

    //获取链表长度
    /*List_TailInsert(L);
    printList(L);
    int len = GetLength(L);
    cout << "链表长度为" << len << endl;
    destroyList(L);*/
}
