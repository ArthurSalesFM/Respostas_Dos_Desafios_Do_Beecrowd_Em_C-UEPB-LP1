#include <stdio.h>
#include <math.h>

int veirificaValoresDeEntrada(int vX, int vY, int i){
    
    if((vX < 1 || vX > 100)){
        //printf("\nO valor para X tem que ser entre 1 à 100\n");
        i--;
        }
    else if((vY < 1 || vY > 100)){
        //printf("\nO valor para Y tem que ser entre 1 à 100\n");
        i--;
    }
    else{
        informaQuemGanhou(vX, vY);
    }
        
    return i;
    
}
 
void informaQuemGanhou(int vx, int vy){
    
    int funcaoRafael = (3 * vx) * (3 * vx) + vy * vy; 
    int funcaoBeto = 2 * (vx * vx) + (5 * vy ) * (5 * vy) ;
    int funcaoCarlos = -100* vx + ( vy * vy * vy);
    
    if(funcaoRafael > funcaoBeto && funcaoRafael > funcaoCarlos){
        printf("Rafael ganhou\n");
    }
    else if(funcaoBeto > funcaoRafael && funcaoBeto > funcaoCarlos){
        printf("Beto ganhou\n");
    }
    else{
        printf("Carlos ganhou\n");
    }
    
}

 
int main() {
 
    int quantidadeDeCasos, valorX, valorY;
    
    //printf("digite a quantidade de testes : ");
    scanf("%d", &quantidadeDeCasos);
    
    for(int i = 0; i < quantidadeDeCasos; i++){
        
        //printf("\nDigite o %dº valor de x e de y : ", i + 1);
        scanf("%d %d", &valorX, &valorY);

        
        i = veirificaValoresDeEntrada(valorX, valorY, i);
        
    }
 
    return 0;
}