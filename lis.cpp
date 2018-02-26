#include<iostream>
#include<cstring>
using namespace std;

int f[10000], b[10000];
int lis(int n) {
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (b[j] < b[i]) {
               f[i]=max(f[i],f[j]+1);
            }
        }
        res = max(res, f[i]);
    }
    return res+1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    printf("%d\n", lis(n));
    return 0;
}
