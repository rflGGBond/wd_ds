#include <cstdio>
#include <iostream>
using namespace std;

/*
    求数组最小未出现正整数
    时间复杂度O(n),空间复杂度O(n)
*/
int FindX(int *a, int n) {
    int b[n +1];
    for(int i=0; i<n; i++) {
        if(a[i]>0 && a[i]<=n) {
            b[a[i]] = 1;
        }
    }
    int i;
    for(i=1; i<=n; i++) {
        if(b[i] == 0) {
            break;
        }
    }
    return i;
}

int main() {
    int a[4] = {-5, 3, 2, 3};
    int b[3] = {1, 2, 3};

    cout << FindX(a, 4) << endl;
    cout << FindX(b, 3) << endl;

    return 0;
}
