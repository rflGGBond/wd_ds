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
    (1).求两个等长升序表的中位数

    (2).并给出注释，要求高效
        采用折半查找的方法，时间复杂度为O(logn)
    (3).分析时间复杂度和空间复杂度
*/
int FindMid(SqList L1, SqList L2) {
    int l1 = 0, r1 = L1.length - 1, l2 = 0, r2 = L2.length - 1;
    while(l1 != r1 || l2 != r2) {
        int mid1 = (l1 + r1) / 2, mid2 = (l2 + r2) / 2;
        if(L1.data[mid1] == L2.data[mid2]) {
            return L1.data[mid1];
        }
        if(L1.data[mid1] < L2.data[mid2]) {
            if((l1+r1)%2==0) {
                l1 = mid1;
                r2 = mid2;
            }
            else {
                l1 = mid1 + 1;
                r2 = mid2;
            }
        }
        else {
            if((l1+r1)%2==0) {
                l2 = mid2;
                r1 = mid1;
            }
            else {
                l2 = mid2 + 1;
                r1 = mid1;
            }
        }
    }

    return L1.data[l1] < L2.data[l2] ? L1.data[l1] : L2.data[l2];
}

int main() {
    SqList L1, L2;
    initList(L1);
    initList(L2);

    int a1[5] = {11, 13, 15, 17, 19};
    int a2[5] = {2, 4, 6, 8, 20};

    for(int i = 0; i < 5; i++) {
        L1.data[i] = a1[i]; L1.length++;
        L2.data[i] = a2[i]; L2.length++;
    }

    cout << FindMid(L1, L2) << endl;

    return 0;
} 
