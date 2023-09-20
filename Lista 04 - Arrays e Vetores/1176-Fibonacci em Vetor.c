/******************************************************************************

Faça um programa que leia um valor e apresente o número de Fibonacci correspondente a este valor lido. 
Lembre que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele.
Todos os valores de Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.

Entrada
A primeira linha da entrada contém um inteiro T, indicando o número de casos de teste. 
Cada caso de teste contém um único inteiro N (0 ≤ N ≤ 60), correspondente ao N-esimo termo da série de Fibonacci.

Saída
Para cada caso de teste da entrada, imprima a mensagem "Fib(N) = X", onde X é o N-ésimo termo da série de Fibonacci.

*******************************************************************************/

/*

                            CÓDIGO UTILIZANDO VETOR(POSSUI ERROS POR CONTA DE ESPAÇO DE MEMÓRIA)


#include <stdio.h>

int retornaValor(int valor){
    unsigned long long valores[valor + 1];
    
    if(valor >= 2){
        valores[0] = 0;
        valores[1] = 1;
        
        for(int i = 2; i <= valor; i++){
           valores[i] = valores[i - 2] + valores[i - 1];
       }
       return valores[valor];
    }
    else{
        valores[0] = 0;
        valores[1] = 1;
        return valores[valor];
    }
}

int main(){
    unsigned int quantidadeDeValores;
    unsigned long long saida;
    
    scanf("%d", &quantidadeDeValores);
    
    for(int x = 0; x < quantidadeDeValores; x++){
        int posicao;
        scanf("%d", &posicao);
        saida = retornaValor(posicao);
        printf("Fib(%d) = %llu\n", posicao, saida);
    }
    return 0;
}

*/

//Programa sem utilizar vetores
#include <stdio.h>

unsigned long long int retornaValor(int valor) {
    unsigned long long int a = 0, b = 1, temp;
    
    if (valor == 0) {
        return a;
    }
    
    for (int i = 2; i <= valor; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

int main() {
    int quantidadeDeValores;
    unsigned long long int saida;

    scanf("%d", &quantidadeDeValores);

    for (int x = 0; x < quantidadeDeValores; x++) {
        int posicao;
        scanf("%d", &posicao);
        saida = retornaValor(posicao);
        printf("Fib(%d) = %llu\n", posicao, saida);
    }
    return 0;
}