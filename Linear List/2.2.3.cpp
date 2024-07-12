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
    对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度O(1)的算法，该算法删除
    顺序表中所有值为x的数据元素
*/
void deleteX(SqList &L, int x) {
    int k = 0;
    for(int i=0; i<L.length; i++) {
        if(L.data[i] != x) {
            L.data[i-k] = L.data[i];
        }
        else {
            k++;
        }
    }
    L.length -= k;
}

int main() {
    SqList L;
    int x = 1;

    initList(L);
    int a[8] = {0, 1, 2, 3, 1, 2, 2, 3};
    for (int i = 0; i < 8; i++)
    {
        L.data[i] = a[i];
        L.length++;
    }

    deleteX(L, x);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    
    return 0;
    
}