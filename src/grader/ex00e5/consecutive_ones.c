#include <stdio.h>
int v[3];
int n, k;

void recur(int len) {
    if (len == n) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (v[j]) {
                if (++count >= k) {
                    for (int i = 0; i < n; ++i) {
                        printf("%d", v[i]);
                    }
                    printf("\n");
                    return;
                }
            } else {
                count = 0;
            }
        }
    } else {
        v[len] = 0;
        recur(len + 1);
        v[len] = 1;
        recur(len + 1);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    recur(0);
}