/******************************************************************************

Rener era um garoto que adorava palíndromos. 
Tanto que inventou um jogo com estes. Dada uma sequência de letras, quantas mais teriam que ser adicionadas, pelo menos, 
de modo que alguma permutação desta sequência formasse um palíndromo. Por exemplo, batata precisa adicionar um b no final, 
para virar o palíndromo batatab. Em outro exemplo, aabb, não precisa adicionar nenhuma letra, pois se faz o palíndromo abba ou baab. 
Em mais um exemplo, abc precisa de duas letras a mais, para formar um palíndromo, que pode ser abcba, acbca, bacab, bcacb, cabac ou cbabc.
Escreva um programa que, dada uma sequência de letras, informe qual é o mínimo de letras que precisam ser adicionadas à sequência, 
para que haja, pelo menos, um anagrama que forme um palíndromo.

Entrada
Haverá diversos casos de teste. Em cada caso, é mostrada uma sequência de, no máximo, 1000 letras. 
Os casos de teste terminam com fim de arquivo.

Saída
Para cada caso de teste, imprima um valor inteiro, correspondente à quantidade mínima de letras a serem acrescentadas para que a 
sequência se torne um palíndromo, em uma de suas permutações.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char sequencia[1001];

    while (scanf("%s", sequencia) != EOF) {
        int ocorrencias[26] = {0};
        int len = strlen(sequencia);

        for (int i = 0; i < len; i++) {
            ocorrencias[sequencia[i] - 'a']++;
        }

        int letras_impares = 0;

        for (int i = 0; i < 26; i++) {
            if (ocorrencias[i] % 2 != 0) {
                letras_impares++;
            }
        }

        if (letras_impares >= 1) {
            letras_impares--;
        }

        printf("%d\n", letras_impares);
    }

    return 0;
}