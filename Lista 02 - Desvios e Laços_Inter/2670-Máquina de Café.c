#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidadeDePessoasPorAndar[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &quantidadeDePessoasPorAndar[i]);
    }

    int totalMinutos = 0;
    int menorTempoTotal = -1;

    for (int andarMaquina = 0; andarMaquina < 3; andarMaquina++) {
        totalMinutos = 0;
        for (int i = 0; i < 3; i++) {
            totalMinutos += quantidadeDePessoasPorAndar[i] * (2 * abs(i - andarMaquina));
        }
        if (menorTempoTotal == -1 || totalMinutos < menorTempoTotal) {
            menorTempoTotal = totalMinutos;
        }
    }

    printf("%d\n", menorTempoTotal);

    return 0;
}