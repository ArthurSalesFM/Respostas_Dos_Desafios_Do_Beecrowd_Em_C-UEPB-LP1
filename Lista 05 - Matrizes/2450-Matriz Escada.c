/******************************************************************************

                            beecrowd | 2450
Matriz Escada
Por OBI - Olimpíada Brasileira de Informática 2014 BR Brazil

Timelimit: 1
Joãozinho está aprendendo sobre matrizes. Hoje ele aprendeu como deixar matrizes na forma escada, e está exercitando. 
Para ajudá-lo, você deve escrever um programa que determine se o resultado dele realmente está no formato correto.

Uma matriz está na forma escada quando, para cada linha, as condições a seguir forem satisfeitas:

Se a linha só possuir zeros, então todas as linhas abaixo desta também só possuem zeros.
Caso contrário, seja X o elemento diferente de zero mais à esquerda da linha; 
então, para todas as linhas abaixo da linha de X, todos os elementos nas colunas à esquerda de X e na coluna de X são iguais a zero.

Entrada
A primeira linha possui dois inteiros N e M (1 ≤ N, M ≤ 500), as dimensões da matriz. 
Cada uma das N linhas seguintes contém M (0 ≤ Mij ≤ 105) inteiros não negativos, os elementos da matriz.

Saída
Seu programa deve produzir uma única linha, contendo o caractere ‘S’ caso a matriz esteja no formato escada, 
ou ‘N’, caso contrário.

*******************************************************************************/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int matriz[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int coluna_atual = 0;

    for (int linha = 0; linha < N; linha++) {
        int elemento_nao_zero_encontrado = 0;

        while (coluna_atual < M && matriz[linha][coluna_atual] == 0) {
            coluna_atual++;
        }

        if (coluna_atual >= M) {
            for (int linha_abaixo = linha + 1; linha_abaixo < N; linha_abaixo++) {
                for (int j = 0; j < M; j++) {
                    if (matriz[linha_abaixo][j] != 0) {
                        printf("N\n");
                        return 0;
                    }
                }
            }
        } else {
            for (int linha_abaixo = linha + 1; linha_abaixo < N; linha_abaixo++) {
                for (int j = 0; j < coluna_atual; j++) {
                    if (matriz[linha_abaixo][j] != 0) {
                        printf("N\n");
                        return 0;
                    }
                }
                if (matriz[linha_abaixo][coluna_atual] != 0) {
                    printf("N\n");
                    return 0;
                }
            }
        }
    }

    printf("S\n");
    return 0;
}