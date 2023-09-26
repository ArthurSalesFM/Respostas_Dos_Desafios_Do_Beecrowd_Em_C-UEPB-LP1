/******************************************************************************

Desenvolvido por: Arthur Felipe MS 
Para as atividades de Laboratório de programação 1 em C (UEPB)

                            beecrowd | 1534
Matriz 123
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia um valor inteiro N que é o tamanho da matriz que deve ser impressa conforme o modelo fornecido.

Entrada
A entrada contém vários casos de teste e termina com EOF. 
Cada caso de teste é composto por um único inteiro N (3 ≤ N < 70), 
que determina o tamanho (linhas e colunas) de uma matriz que deve ser impressa.

Saída
Para cada N lido, apresente a saída conforme o exemplo fornecido.

*******************************************************************************/

#include <stdio.h>

void preencheMatriz(int matriz[100][100], int tamanho);
void imprimeMatriz(int matriz[100][100], int tamanho);

int main() {
    int tamanho;
    int matriz[100][100];

    while (scanf("%d", &tamanho) != EOF) {
        
        if (tamanho <= 100) {
            preencheMatriz(matriz, tamanho);
            imprimeMatriz(matriz, tamanho);
        } 
        else {
            printf("Tamanho da matriz excede o tamanho máximo permitido (100).\n");
        }
    }
    return 0;
}

void preencheMatriz(int matriz[100][100], int tamanho) {
    
    for (int i = 0; i < tamanho; i++) {
        
        for (int j = 0; j < tamanho; j++) {
            
            if (i == j) {
                
                if((tamanho / 2) == i && ( tamanho / 2 ) == j && tamanho % 2 != 0){
                    matriz[i][j] = 2;
                }
                else{
                    matriz[i][j] = 1;
                }
                
            } 
            else if (i == tamanho - j - 1) {
                matriz[i][j] = 2;
            } 
            else {
                matriz[i][j] = 3;
            }
        }
    }
}

void imprimeMatriz(int matriz[100][100], int tamanho) {
    
    for (int i = 0; i < tamanho; i++) {
        
        for (int j = 0; j < tamanho; j++) {
            printf("%d", matriz[i][j]);
        }
        
        printf("\n");
    }
}

