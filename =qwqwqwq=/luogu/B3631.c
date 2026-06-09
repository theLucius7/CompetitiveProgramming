#include <stdio.h>
#include <stdbool.h>

const int N = 1E6;

int nxt[1000010], v[1000010], fv[1000010], id = 0;

int main() {
    for (int i = 0; i < N; i++) {
        nxt[i] = -1;
        fv[i] = -1;
    }

    fv[1] = 0;
    v[0] = 1;
    nxt[0] = -1;
    id = 1;

    int q;
    scanf("%d", &q);

    while (q--) {
        int op;
        scanf("%d", &op);
        
        if (op == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            nxt[id] = nxt[fv[x]];
            v[id] = y;
            fv[y] = id;
            nxt[fv[x]] = id;
            id++;
        } else if (op == 2) {
            int x;
            scanf("%d", &x);

            if (fv[x] == -1 || nxt[fv[x]] == -1) {
                printf("0\n");
            } else {
                printf("%d\n", v[nxt[fv[x]]]);
            }
        } else {
            int x;
            scanf("%d", &x);

            if (nxt[fv[x]] == -1) {
                continue;
            }

            int y = v[nxt[fv[x]]];
            nxt[fv[x]] = nxt[fv[y]];
            fv[y] = -1;
        }
    }

    
    
}
