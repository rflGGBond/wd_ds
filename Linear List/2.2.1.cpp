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
    从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。空出的位置由最后一个
    元素填补，若顺序表为空，则显示出错信息并退出运行
*/
bool del_min(SqList &L, int &e) {
    if(L.length == 0) return false;
    int pos = 0, min = L.data[0];

    for(int i=1; i<L.length; i++) {
        if(min > L.data[i]) {
            min = L.data[i];
            pos = i;
        }
    }
    e = L.data[pos];
    L.data[pos] = L.data[L.length-1];
    L.length--;

    return true;
}

int main() {
    SqList L;
    int e;

    initList(L);
    for(int i=0; i<10; i++) {
        L.data[i] = rand()%100;
        L.length++;
    }

    for(int i=0; i<L.length; i++) {
        cout << L.data[i] << " ";
    }

    if(del_min(L, e)) {
        cout << "删除最小值为：" << e << endl;
        cout << L.length << endl;
        for(int i=0; i<=L.length; i++) {
            cout << L.data[i] << " ";
        }
    }
    else {
        cout << "顺序表为空" << endl;
    }

    return 0;
}