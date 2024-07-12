#include <cstdio>
#include <iostream>
#include <algorithm>
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
    输出三个有序表中的相同元素
*/
void FindSame(SqList L1, SqList L2, SqList L3) {
    int i = 0, j = 0, k = 0;
    while(i < L1.length && j < L2.length && k < L3.length) {
        if(L1.data[i] == L2.data[j] && L2.data[j] == L3.data[k]) {
            cout << L1.data[i] << " ";
            i++, j++, k++;
        }
        else {
            int maximum = max(L1.data[i], max(L2.data[j], L3.data[k]));
            if(L1.data[i] < maximum) i++;
            if(L2.data[j] < maximum) j++;
            if(L3.data[k] < maximum) k++;
        }
    }
}

int main() {
    SqList L1, L2, L3;
    initList(L1);
    initList(L2);
    initList(L3);
    int a[3] = {1, 2, 3}, b[3] = {2, 3, 4}, c[3] = {-1, 0 ,2};
    for(int i = 0; i < 3; i++) {
        L1.data[i] = a[i]; L1.length++;
        L2.data[i] = b[i]; L2.length++;
        L3.data[i] = c[i]; L3.length++;
    }

    FindSame(L1, L2, L3);

    return 0;
}