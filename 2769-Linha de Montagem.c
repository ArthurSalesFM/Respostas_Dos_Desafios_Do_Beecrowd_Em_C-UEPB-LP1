#include <stdio.h>

#define MAX_N 1000

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int e1, e2;
        scanf("%d %d", &e1, &e2);

        int a1[MAX_N], a2[MAX_N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &a1[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &a2[i]);
        }

        int t1[MAX_N - 1], t2[MAX_N - 1];
        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &t1[i]);
        }
        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &t2[i]);
        }

        int x1, x2;
        scanf("%d %d", &x1, &x2);

        int dp1[MAX_N], dp2[MAX_N];
        dp1[0] = e1 + a1[0];
        dp2[0] = e2 + a2[0];

        for (int i = 1; i < N; i++) {
            dp1[i] = a1[i] + ((dp1[i - 1] < dp2[i - 1] + t2[i - 1]) ? dp1[i - 1] : dp2[i - 1] + t2[i - 1]);
            dp2[i] = a2[i] + ((dp2[i - 1] < dp1[i - 1] + t1[i - 1]) ? dp2[i - 1] : dp1[i - 1] + t1[i - 1]);
        }

        int result = (dp1[N - 1] + x1 < dp2[N - 1] + x2) ? dp1[N - 1] + x1 : dp2[N - 1] + x2;
        printf("%d\n", result);
    }

    return 0;
}