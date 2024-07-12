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
    有序表查找x，成功则与后一位数字交换位置；失败则插入x后依旧保持有序
*/
void FindX(SqList &L, int x) {
    int left = 0, right = L.length - 1;
    int mid = (left + right) / 2;
    bool flag = false;

    while (left <= right && flag == false) {
        if(x == L.data[mid]) {
            flag = true;
            if(mid < L.length - 1) {
                int temp = x;
                L.data[mid] = L.data[mid + 1];
                L.data[mid + 1] = temp;
            }
        }
        if(x < L.data[mid]) {
            right = mid - 1;
            mid = (left + right) / 2; 
        }
        if(x > L.data[mid]) {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }

    if(flag == false) {
        for(int i=L.length-1; i>right; i--) {
            L.data[i+1] = L.data[i];
        }
        L.data[right+1] = x;
        L.length++;
    }
}

int main() {
    SqList L;
    initList(L);
    int a[7] = {2, 4, 6, 8, 10, 12, 14};
    for(int i=0; i<7; i++) {
        L.data[i] = a[i];
        L.length++;
    }
    FindX(L, 7);
    for(int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }
    return 0;
}