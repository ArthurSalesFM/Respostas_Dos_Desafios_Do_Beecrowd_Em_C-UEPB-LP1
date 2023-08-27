#include <stdio.h>
 
int main() {
    int a, b, c, maior_ab, maior;
    
    // Lê os três valores inteiros
    scanf("%d %d %d", &a, &b, &c);
    
    // Calcula o maior entre a e b
    maior_ab = (a + b + abs(a - b)) / 2;
    
    // Calcula o maior entre maior_ab e c
    maior = (maior_ab + c + abs(maior_ab - c)) / 2;
    
    // Exibe o resultado
    printf("%d eh o maior\n", maior);
    
    return 0;
}