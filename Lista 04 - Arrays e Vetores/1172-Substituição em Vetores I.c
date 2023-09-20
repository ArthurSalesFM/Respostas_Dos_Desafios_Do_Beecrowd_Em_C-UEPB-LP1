/******************************************************************************

Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os valores nulos e negativos do vetor X por 1. 
Em seguida mostre o vetor X.

Entrada
A entrada contém 10 valores inteiros, podendo ser positivos ou negativos.

Saída
Para cada posição do vetor, escreva "X[i] = x", onde i é a posição do vetor e x é o valor armazenado naquela posição.

*******************************************************************************/

#include <stdio.h>

int main(){
    int valores[10];
    
    for(int i = 0; i < 10; i++){
        //printf("Digite o %dº valor : ", (i + 1));
        scanf("%d",&valores[i]);
    }
    
    for(int x = 0; x < 10; x++){
        if(valores[x] <= 0){
            valores[x] = 1;
        }
        printf("X[%d] = %d\n", x, valores[x]);
    }

    return 0;
}