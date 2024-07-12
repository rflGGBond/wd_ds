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
    从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，
    若s和t不合理或顺序表为空，则显示出错信息并退出运行
*/
bool deleteX(SqList &L, int s, int t) {
    if(s>=t || L.length==0) return false;
    int k = 0;
    for(int i=0; i<L.length; i++) {
        if(L.data[i]>=s && L.data[i]<=t) {
            k++;
        }
        else {
        L.data[i-k] = L.data[i];
        }
    }
    L.length -= k;
    
    return true;
}

int main() {
    SqList L;
    int s, t;
    initList(L);
    int a[9] = {0, 1, 2, 4, 2, 9, 6, 8, 7};
    for (int i = 0; i < 9; i++)
    {
        L.data[i] = a[i];
        L.length++;
    }
    cin >> s >> t;
    deleteX(L, s, t);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    return 0;
}