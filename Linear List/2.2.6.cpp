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
    合并两个表
*/
void merge(SqList &La, SqList &Lb, SqList &Lc) {
    int i = 0, j = 0, k = 0;
    while(i < La.length && j < Lb.length) {
        if(La.data[i] < Lb.data[j]) {
            Lc.data[k++] = La.data[i++];
        }
        else {
            Lc.data[k++] = Lb.data[j++];
        }
    }
    while(i < La.length) {
        Lc.data[k++] = La.data[i++];
    }
    while(j < Lb.length) {
        Lc.data[k++] = Lb.data[j++];
    }
    Lc.length = La.length + Lb.length;
}

int main() {
    SqList La, Lb, Lc;
    initList(La);
    initList(Lb);
    initList(Lc);
    int a[5] = {1, 3, 5, 7, 9};
    int b[7] = {2, 4, 6, 8, 10, 12, 14};

    for(int i = 0; i < 5; i++) {
        La.data[i] = a[i];
        La.length++;
    }
    for(int i = 0; i < 7; i++) {
        Lb.data[i] = b[i];
        Lb.length++;
    }

    merge(La, Lb, Lc);  // 合并两个表
    for(int i = 0; i < La.length; i++) {
        cout << La.data[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < Lb.length; i++) {
        cout << Lb.data[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < Lc.length; i++) {
        cout << Lc.data[i] << " ";
    }

    return 0;
}