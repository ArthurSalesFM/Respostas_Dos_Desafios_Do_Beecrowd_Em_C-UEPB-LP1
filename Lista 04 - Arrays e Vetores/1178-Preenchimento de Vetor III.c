/******************************************************************************

Leia um valor X. Coloque este valor na primeira posição de um vetor N[100]. 
Em cada posição subsequente de N (1 até 99), coloque a metade do valor armazenado na posição anterior, 
conforme o exemplo abaixo. Imprima o vetor N.

Entrada
A entrada contem um valor de dupla precisão com 4 casas decimais.

Saída
Para cada posição do vetor N, escreva "N[i] = Y", onde i é a posição do vetor e Y é o valor armazenado naquela posição. 
Cada valor do vetor deve ser apresentado com 4 casas decimais.

*******************************************************************************/

#include <stdio.h>

int main(){
    long double valores[100], valor;
    
    scanf("%Lf", &valor);
    
    valores[0] = valor;
    
    for(int y = 1; y < 100; y++){
        valores[y] = valores[y - 1] / 2.0;
    }
    
    for(int x = 0; x < 100; x++){
        printf("N[%d] = %.4Lf\n", x, valores[x]);
    }

    return 0;
}