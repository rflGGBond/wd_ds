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
    将一维数组前m和后n个元素对调或者理解为将线性表的前m和后n个元素对调
    与2.2.10基本相同，只是对调的元素范围不同
    时间复杂度为O(n)，空间复杂度为O(1)
*/
void reverse(SqList &L, int l, int r, int size) {
    if(l>=r || r>=size) return;
    int mid = (l+r)/2;
    for(int i=0; i<=mid-l; i++) {
        int temp = L.data[l+i];
        L.data[l+i] = L.data[r-i];
        L.data[r-i] = temp;
    }
}
void Exchange(SqList &L, int m, int n) {
    reverse(L, 0, m+n-1, L.length);
    reverse(L, 0, n-1, L.length);
    reverse(L, n, m+n-1, L.length);
}

int main() {
    SqList L;
    initList(L);
    int m = 5, n = 4;
    for(int i=0; i<m+n; i++) {
        L.data[i] = i+1;
        L.length++;
    }
    Exchange(L, m, n);
    for(int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }
    return 0;
}