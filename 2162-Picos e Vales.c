#include <stdio.h>

int main() {

    int paisagens, atual, anterior, ehPadrao = 1, pico;

    scanf("%d",&paisagens);
    if (paisagens == 1) {

        scanf("%d",&atual);
        printf("%d\n", ehPadrao);
    } else if (paisagens == 2) {
    
        scanf("%d",&anterior);
        scanf("%d",&atual);
        printf("%d\n", !(atual == anterior));
    } else {
        scanf("%d",&anterior);
        scanf("%d",&atual);
        paisagens -= 2;
        pico = atual > anterior;
        do {
            anterior = atual;
            scanf("%d",&atual);
            paisagens--;
            if (ehPadrao) {
                if (pico) {
                    ehPadrao = atual < anterior ;
                    pico = 0;
                } else {
                    ehPadrao = atual > anterior;
                    pico = 1;
                }
            }
        } while (paisagens > 0);
        printf("%d\n",ehPadrao);
    }
    return 0;
}