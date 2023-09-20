#include <stdio.h>

void verificaVitoria(int p, int j1, int j2, int r, int a){
    
    int result = (j1 + j2) % 2;
    
    if(r == 1 && a == 1 ){
        // se o jogador 1 roubar e o jogador 2 acusar o roubo então o jogador 2 ganha
        printf("Jogador 2 ganha!\n");
    }
    else if(r == 1 && a == 0 ){
        // se o jogador 2 não acuse o roubo e o jogador 1 roubar então o jogador 1 ganha
        printf("Jogador 1 ganha!\n");
    }
    else if(r == 0 && a == 1){
        // se o jogador 2 acuse o roubo, mas o jogador 1 não tiver roubado então o jogador 1 ganha
        printf("Jogador 1 ganha!\n");
    }
    else{
        // se o jogador 1 não roubar e o jogador 2 não acusar o roubo o jogo segue como descrito anteriormente
        
        if(p == 1 && result == 0){
            printf("Jogador 1 ganha!\n");
        }
        else if(p == 1 && result == 1){
            printf("Jogador 2 ganha!\n");
        }
        else if(p == 0 && result == 0){
            printf("Jogador 2 ganha!\n");
        }
        else{
            printf("Jogador 1 ganha!\n");
        }
    }
}


int main(){
    
    int p, j1, j2, r, a;
    
    //printf("Digite os valores : ");
    scanf("%d%d%d%d%d", &p, &j1, &j2, &r, &a);
    
    verificaVitoria(p, j1, j2, r, a);

    return 0;
}