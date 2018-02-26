#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3;
char str[N], buf[N];//buffer
int vis[N], total, len;
int ans[N];
void arrange(int num) {
    if (num == len){
        printf("%s\n", buf);
        total++;
      printf("%d%d%d%d\n",ans[0],ans[1],ans[2],ans[3]);
        return;
    }
	for (int i = 0; i < len; ++i) {
        if (!vis[i]) {
            int j;
            for (j = i + 1; j < len; ++j) {
                if ( !vis[j]&&str[j]==str[i] ) {
                    break;
                }
            }
            if (j == len) {
                vis[i] = 1;
                buf[num] = str[i];
                ans[num]=i;
                arrange(num + 1);
                vis[i] = 0;
            }
        }
    }
}
int main() {
    while (~scanf("%s",str)) {
        len = strlen(str);
        sort(str, str + len);
        total = 0;
        buf[len] = '\0';
        arrange(0);
        printf("Total %d\n", total);
    }
    return 0;
}
