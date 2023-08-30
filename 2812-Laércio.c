/******************************************************************************

Armandinho tem um amigo o tanto quanto chato, chamado Laércio. Quando jogam o jogo do mestre manda, um jogo onde alguém dá uma ordem e alguém a cumpre, e em vez de dar ordens legais como subir em uma árvore, pular o muro, plantar bananeira ou organizar manifestações para derrubar o governo (independente de quem estiver no poder) ele sempre pede algo maçante. Em sua última partido, Laércio exigiu que Armandinho ordenasse uma lista de números, de forma que apenas os números ímpares aparecessem e o primeiro item seja o maior, o segundo seja o menor, o terceiro o segundo maior, o quarto seja o segundo menor e assim por diante. Como fazer isso a mão é muito chato, Armandinho procurou sua ajuda.

Entrada
A entrada consiste de um inteiro N que representa o número de casos testes ( 1<N<1000 ). Cada caso teste começa com um inteiro M, que representa o tamanho da lista (0<M<100). Seguem M inteiros Mi (0<Mi < 1000) que representam a lista de Laércio.

Saída
Imprima a lista ordenada como Laércio requisitou, com um espaço entre os valores, pulando uma linha a cada caso teste.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void organizaImpares(int vetor[], int tamanho) {
    int impares[tamanho];
    int indiceImpares = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 1) {
            impares[indiceImpares] = vetor[i];
            indiceImpares++;
        }
    }

    bubbleSort(impares, indiceImpares);
    
    int vetorOrganizado[tamanho];
    
    int indiceMaior = 0;
    int indiceMenor = indiceImpares - 1;

    for (int i = 0; i < indiceImpares; i++) {
        if (i % 2 == 0) {
            vetorOrganizado[i] = impares[indiceMaior];
            indiceMaior++;
        } else {
            vetorOrganizado[i] = impares[indiceMenor];
            indiceMenor--;
        }
    }

    for (int i = 0; i < indiceImpares; i++) {
        printf("%d", vetorOrganizado[i]);
        
        if (i < indiceImpares - 1) {
            printf(" ");
        }
    }
    
    printf("\n");
}

int main() {
    int quantidadeDeTestes;
    
    scanf("%d", &quantidadeDeTestes);

    for (int i = 0; i < quantidadeDeTestes; i++) {
        int quantidadeDeEntrada;
        scanf("%d", &quantidadeDeEntrada);

        int valores[quantidadeDeEntrada];

        for (int y = 0; y < quantidadeDeEntrada; y++) {
            scanf("%d", &valores[y]);
        }

        organizaImpares(valores, quantidadeDeEntrada);
    }

    return 0;
}
