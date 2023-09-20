#include <stdio.h>

int main(){
    int quantidade_duendes, identificador, soma = 0;
    scanf("%d", &quantidade_duendes);
    for (int i = 1; i <= quantidade_duendes; i++) {
        scanf("%d", &identificador);
        soma += identificador;
    }
    
    if (quantidade_duendes >= 2) quantidade_duendes /= 2;
    //if (quantidade_duendes == 2 || quantidade_duendes == 3) quantidade_duendes = 2;
    if(quantidade_duendes == 3) quantidade_duendes = 2;
    soma /= quantidade_duendes;
    
    if(soma == 1){
        soma = 2;
    }
    printf("%d\n", soma);

    return 0;
}