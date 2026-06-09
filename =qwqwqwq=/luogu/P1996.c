#include <stdio.h>
#include <stdbool.h>

int N = 110;
int a[110];
bool vis[110];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cur = 0, cnt = n;
    for (int i = 0; ; ) {
        if (!vis[i]) {
            cur++;
        }
        if (cur == m) {
            printf("%d ", i + 1);
            vis[i] = true;
            cur = 0;
            cnt--;

            if (cnt == 0) {
                break;
            }
        }

        i++;
        if (i == n) {
            i = 0;
        }
    }


    
    
}
