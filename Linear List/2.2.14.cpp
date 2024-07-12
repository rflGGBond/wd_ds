#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    求三元组最小距离
    时间复杂度O(n),空间复杂度O(n)
*/
int FindMinDis(int *a, int *b, int *c, int m, int n, int p) {
    int minDis = INT_MAX;
    int i = 0, j = 0, k = 0;
    while(i < m && j < n && k < p && minDis > 0) {
        int dis = abs(a[i] - b[j]) + abs(b[j] - c[k]) + abs(c[k] - a[i]);
        if(dis < minDis) {
            minDis = dis;
        }
        if(a[i] == min(min(a[i], b[j]), c[k])) i++;
        else if(b[j] == min(min(a[i], b[j]), c[k])) j++;
        else k++;
    }

    return minDis;
}

int main() {
    int a[3] = {-1, 0, 9}, b[4] = {-25, -10, 10, 11}, c[5] = {2, 9, 17, 30, 41};
    cout << FindMinDis(a, b, c, 3, 4, 5) << endl;

    return 0;
}