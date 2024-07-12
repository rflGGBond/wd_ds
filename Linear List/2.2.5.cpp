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
    删除有序表中重复元素
*/
bool deleteRepeated(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    int i, j;
    for(i=0, j=1; j<L.length; j++) {
        if(L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
 }

 int main() {
    SqList L;
    initList(L);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        L.data[i] = temp;
    }
    L.length = n;
    deleteRepeated(L);
    for(int i=0; i<L.length; i++){
        cout << L.data[i] << " ";
    }
    return 0;
}