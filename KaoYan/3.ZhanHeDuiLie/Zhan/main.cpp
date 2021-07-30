#include <iostream>

using namespace std;

#define MaxSize 20
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    return false;
}

bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}

bool printStack(SqStack S) {
    cout << "[";
    int p = S.top;
    while (p != -1) {
        cout << S.data[p];
        if (p == 0) {
            cout << "]" << endl;
        } else {
            cout << ",";
        }
        p--;
    }
    return true;
}

int main() {
    SqStack S;
    InitStack(S);
    int x;
    cout << "请输入:";
    cin >> x;
    while (x != 9999) {
        Push(S, x);
        cout << "请输入:";
        cin >> x;
    }
    printStack(S);
    return 0;
}
