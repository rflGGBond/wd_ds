#include <cstdio>
using namespace std;

/*
    求表的众数
    时间复杂度O(n),空间复杂度O(1)
*/
int FindMost(int* a, int n) {
    int x = a[0], count = 1;
    for(int i=1; i<n; i++) {
        if(a[i] == x) {
            count++;
        } else {
            if(count > 0) {
                count--;
            }
            else {
                x = a[i];
                count = 1;
            }
        }
    }
    if(count > 0) {
        for(int i=count=0; i<n; i++) {
            if(a[i] == x) {
                count++;
            }
        }
    }
    if(count > n/2) return x;
    else return -1;
}

int main() {
    int a[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int b[8] = {0, 5, 5, 3, 5, 1, 5, 7};

    printf("%d\n", FindMost(a, 8));
    printf("%d\n", FindMost(b, 8));

    return 0;
}