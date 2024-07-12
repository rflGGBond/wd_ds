#include <cstdio>
#include <iostream>
#define MaxSize 50
using namespace std;

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

// 初始化顺序表
void initList(SqList &L) {
    L.length = 0;
}

/*
    设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
*/
void reverse(SqList &L) {
    int temp = 0;

    for(int i=0; i<L.length/2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}

int main() {
    SqList L;

    initList(L);
    for(int i=0; i<10; i++) {
        L.data[i] = i;
        L.length++;
    }

    cout << "原顺序表：" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;

    reverse(L);

    cout << "逆置后：" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    
    return 0;
}