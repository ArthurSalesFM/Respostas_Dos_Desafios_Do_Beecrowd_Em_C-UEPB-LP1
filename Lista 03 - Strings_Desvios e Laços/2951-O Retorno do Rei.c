/******************************************************************************

Frodo e Sam estão prestes a conseguir jogar o anel na Montanha da Perdição, porém Gollum os atrapalha.
Uma pequena pausa na história. Senhor dos Anéis, além de ser um dos maiores clássicos literários e cinematográficos da humanidade, 
é uma história que deixa evidente o valor da amizade. Dê valor às boas amizades :) Despause.
Gollum é um ser infeliz e que não suporta a amizade. Para que Frodo e Sam consigam passar por ele, 
eles precisam recitar runas que entoam amizade. Cada runa é representada por uma letra do alfabeto, 
e indica uma quantidade de amizade que ela emite, podendo ser positiva ou negativa 
(sim, existem as runas que representam as más amizades). 
Dada a quantidade de amizade necessária para derrotar Gollum, uma lista de runas e seus respectivos valores de amizade e 
as runas que Sam e Frodo recitaram, dê o valor final de amizade que Frodo e Sam conseguiram e se foi possível ou não derrotar Gollum.

Entrada
A primeira linha da entrada é composta por dois inteiros N(1 <= N) e G(G <= 100), indicando, 
respectivamente, a quantidade de runas existentes, e a quantidade de amizade necessária para derrotar Gollum.
As próximas N linhas são compostas por um caractere Ri('A' <= Ri <= 'Z') e um inteiro Vi(-100 <= Vi <= 100), 
indicando, respectivamente, a runa e o valor de amizade que ela agrega. A próxima linha é iniciada por um inteiro X, 
indicando a quantidade de runas recitadas por Frodo e Sam. A última linha da entrada é composta por X caracteres, 
indicando as runas recitadas por Frodo e Sam.

Saída
A primeira linha da saída deve conter a quantidade de valor de amizade. A segunda linha deve conter uma das seguintes mensagens:
● “My precioooous”, se Gollum vencer;
● “You shall pass!”, se Frodo e Sam vencerem.

*******************************************************************************/

#include <stdio.h>

int main() {
    int quantidadeDeRunas, quantidadeDeAmizade;

    scanf("%d", &quantidadeDeRunas);
    scanf("%d", &quantidadeDeAmizade);

    char runas[quantidadeDeRunas];
    int valores[quantidadeDeRunas];

    for (int i = 0; i < quantidadeDeRunas; i++) {
        scanf(" %c", &runas[i]);
        scanf("%d", &valores[i]);
    }

    int runasRecitadas = 0;
    scanf("%d", &runasRecitadas);

    char recitadas[runasRecitadas];
    for (int i = 0; i < runasRecitadas; i++) {
        scanf(" %c", &recitadas[i]);
    }

    int valorAmizade = 0;

    for (int i = 0; i < runasRecitadas; i++) {
        char runaRecitada = recitadas[i];
        
        for (int j = 0; j < quantidadeDeRunas; j++) {
            if (runaRecitada == runas[j]) {
                valorAmizade += valores[j];
                break;
            }
        }
    }

    printf("%d\n", valorAmizade);

    if (valorAmizade >= quantidadeDeAmizade) {
        printf("You shall pass!\n");
    } else {
        printf("My precioooous\n");
    }

    return 0;
}