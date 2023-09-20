/******************************************************************************

Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. 
Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.

Entrada
Leia três valores de ponto flutuante (double) A, B e C.

Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". 
Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto, com uma mensagem correspondente conforme exemplo abaixo. 
Imprima sempre o final de linha após cada mensagem.
*******************************************************************************/

#include <stdio.h>
#include <math.h>

void calculaRaizes(float b, float discrim, float a) {
    float x1, x2;

    x1 = (-b + sqrt(discrim)) / (2 * a);
    x2 = (-b - sqrt(discrim)) / (2 * a);

    printf("R1 = %.5f\nR2 = %.5f\n", x1, x2);
}

void verificaPossibilidades(float a, float b, float c) {
    if (a == 0) {
        printf("Impossivel calcular\n");
    } else {
        float discriminante = (b * b) - 4 * a * c;
        if (discriminante < 0) {
            printf("Impossivel calcular\n");
        } else {
            calculaRaizes(b, discriminante, a);
        }
    }
}

int main() {
    float a, b, c;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    verificaPossibilidades(a, b, c);

    return 0;
}