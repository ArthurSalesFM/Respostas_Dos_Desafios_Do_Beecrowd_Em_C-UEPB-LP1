/******************************************************************************

Batuke é um cachorro com comportamento repetitivo que tem uma rotina particular quando sai para caminhar na sua vizinhança. 
A vizinhança também é de certa forma particular: uma matriz N x N que batuke percorre rotineiramente em espiral. 
Batuke inicia percorrendo: 1 célula à direita, uma abaixo, seguida por duas à esquerda, duas acima, 
então 3 à direita, 3 para baixo, então 4, e assim por diante.

Lucas (o dono de Batuke), leva Batuke de carro para a célula inicial e o cão sempre segue sua rotina de corrida pelas 
células de sua vizinhança.

Por exemplo, se a vizinhança tem tamanho N = 4, as células são enumeradas como segue:


e o percurso feito por Batuke, iniciando na célula 1,1 (célula superior esquerda é 0,0) é:

6,7,11,10,9,5,1,2,3,4,8,12,16,15,14,13

Neste caso, a rotina de Batuke o faz caminhar por 16 células no total.

Mas Batuke não compreende nada sobre fronteiras e ele sempre faz sua rotina 
(mesmo se ele tem que caminhar por diversas células a mais), para atravessar todas as células da vizinhança. 
Se a célula inicial for 2,2 por exemplo, a travessia em espiral (apenas as células da vizinhança são mostradas) 
é: 11,12,16,15,14,10,6,7,8,13,9,5,1,2,3,4.

Neste caso, Batuke caminha por 24 células no total. 
Lucas sabe que você está estudando Computação e ele pediu a você um programa para resolver este problema: 
dado a vizinhança de N linhas por N colunas e uma célula inicial, você deverá mostrar o percurso em espiral e 
o total células percorridas.

Entrada
A entrada consiste em três números inteiros: N (2 < N ≤ 10 ), F e C. 
N é o número de linhas na vizinhança (células enumeradas em 1..NxN, por linhas, da esquerda para a direita). 
F e C indica linha e coluna aonde Batuke inicia o seu percurso.

Saída
A saída consiste em 2 linhas. A primeira linha contém uma lista contendo as células da vizinhança, 
ordenadas pelo percurso que Batuke e separadas por um espaço em branco. 
A segunda linha mostra o número total de células percorridas por Batuke.

*******************************************************************************/

#include <stdio.h>

void imprimePercurso(int tamanho, int matriz[tamanho][tamanho], int pontoX, int pontoY) {
    int horizontal = pontoX;
    int vertical = pontoY;
    
    int contadorPassos, direcao, contadorPassosAtual, contadorLeitura, totalNaoZero, naoZeroContador;
    contadorPassos = direcao = contadorPassosAtual = contadorLeitura = totalNaoZero = naoZeroContador = 0;
    
    int passos = 1;
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] != 0) {
                totalNaoZero++;
            }
        }
    }
    
    while (naoZeroContador < totalNaoZero) {
        contadorLeitura += 1;
        
        if (matriz[horizontal][vertical] != 0) {
            printf("%d", matriz[horizontal][vertical]);
            naoZeroContador++;
            
            if (naoZeroContador < totalNaoZero) {
                printf(" ");
            }
        }
        
        contadorPassos++;
        
        switch (direcao) {
            case 0: vertical++; break;
            case 1: horizontal++; break;
            case 2: vertical--; break;
            case 3: horizontal--; break;
        }
        
        contadorPassosAtual++;

        if (contadorPassosAtual == passos) {
            contadorPassosAtual = 0;
            direcao = (direcao + 1) % 4;
            
            if (direcao == 0 || direcao == 2) {
                passos++;
            }
        }
    }
    
    printf("\n%d\n", contadorLeitura);
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    int margem = N - 1;
    int tamanhoDaMatriz = N + margem * 2;
    
    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];

    for (int i = 0; i < tamanhoDaMatriz; i++) {
        for (int j = 0; j < tamanhoDaMatriz; j++) {
            matriz[i][j] = 0;
        }
    }
    
    int contador = 1;
    
    for (int i = margem; i < tamanhoDaMatriz - margem; i++) {
        for (int j = margem; j < tamanhoDaMatriz - margem; j++) {
            matriz[i][j] = contador;
            contador++;
        }
    }
    
    int inicioX, inicioY;
    
    scanf("%d %d", &inicioX, &inicioY);
    
    inicioX = inicioX + margem;
    inicioY = inicioY + margem;
    
    imprimePercurso(tamanhoDaMatriz, matriz, inicioX, inicioY);

    return 0;
}
