#include <stdio.h>

int diasDosMeses(int mes) {
    int dias[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dias[mes - 1];
}

int diasParaONatal(int diaAtual, int mesAtual) {
    int mesDoNatal = 12;
    int diaDoNatal = 25;
    int diasRestantes = 0;

    while (mesAtual != mesDoNatal || diaAtual != diaDoNatal) {
        diasRestantes++;
        diaAtual++;

        if (diaAtual > diasDosMeses(mesAtual)) {
            diaAtual = 1;
            mesAtual++;

            if (mesAtual > 12) {
                mesAtual = 1;
            }
        }
    }
    return diasRestantes;
}

int main(void) {
    int diaAtual, mesAtual;

    while (scanf("%d %d", &mesAtual, &diaAtual) != EOF) {
        
        int diasQueFaltam = diasParaONatal(diaAtual, mesAtual);

        if (diasQueFaltam == 1) {
            printf("E vespera de natal!\n");
        } 
        else if (diasQueFaltam == 0) {
            printf("E natal!\n");
        } 
        else if (diasQueFaltam >= 360) {
            printf("Ja passou!\n");
        } 
        else {
            printf("Faltam %d dias para o natal!\n", diasQueFaltam);
        }
    }

    return 0;
}