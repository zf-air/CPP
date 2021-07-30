#include <iostream>

using namespace std;
#define MaxSize 20
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if (Q.rear == MaxSize)
        return false;
    Q.data[Q.rear++] = x;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front++];
    return true;
}

bool printSqQueue(SqQueue Q) {
    int p = Q.front;
    cout << "[";
    while (p != Q.rear) {
        cout << Q.data[p];
        if (Q.rear - p == 1)
            cout << "]" << endl;
        else
            cout << ",";
        p++;
    }
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    int x;
    cout << "请输入:";
    cin >> x;
    while (x != 9999) {
        EnQueue(Q, x);
        cout << "请输入:";
        cin >> x;
    }
    printSqQueue(Q);
    return 0;
}
