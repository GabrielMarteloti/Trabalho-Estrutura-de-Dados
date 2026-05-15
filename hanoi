#include <stdio.h>

void hanoi(int n, char o, char d, char a, int *m) {
    if (n == 1) { // Caso base: apenas um disco
        printf("Move disco 1 de %c para %c\n", o, d);
        (*m)++;
        return;
    }
    hanoi(n - 1, o, a, d, m); // Redução: move n-1 para auxiliar
    printf("Move disco %d de %c para %c\n", n, o, d);
    (*m)++;
    hanoi(n - 1, a, d, o, m); // Redução: move n-1 do auxiliar para destino
}

int main() {
    int n, t = 0;
    printf("Discos: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B', &t);
    printf("Total: %d\n", t);
    return 0;
}
