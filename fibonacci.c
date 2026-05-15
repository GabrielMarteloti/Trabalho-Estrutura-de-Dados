#include <stdio.h>
#include <stdlib.h>

long long fib_rec(int n, long long *calls) {
    (*calls)++; //contador de chmadas 
    if (n <= 1) return n; //caso base
    return fib_rec(n - 1, calls) + fib_rec(n - 2, calls); //duas chamadas novas
}

long long fib_memo(int n, long long *memo, long long *calls) {
    (*calls)++;
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_memo(n - 1, memo, calls) + fib_memo(n - 2, memo, calls);
    return memo[n];
}

int main() {
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    long long c1 = 0, c2 = 0;
    long long r1 = fib_rec(n, &c1);
    long long *memo = (long long *)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) memo[i] = -1;
    long long r2 = fib_memo(n, memo, &c2);
    printf("\n--- FIBONACCI ---\nIngenuo: %lld (Chamadas: %lld)\nMemoizado: %lld (Chamadas: %lld)\n", r1, c1, r2, c2);
    free(memo);
    return 0;
}
