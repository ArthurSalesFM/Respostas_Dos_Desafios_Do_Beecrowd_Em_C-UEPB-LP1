#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        n += 1; // Corrige o erro de adicionar +1 no valor

        if (n % 2 == 0) {
            n++; // Se n for par, incrementa para próximo ímpar
        }

        if (n % 7 == 0 && (is_prime(n + 2))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}