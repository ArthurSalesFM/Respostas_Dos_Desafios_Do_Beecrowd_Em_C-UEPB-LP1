#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tabelaDeAlimento(const char *nome) {
    int valores[7] = {120, 85, 85, 70, 56, 50, 34};
    const char *nomesDosAlimentos[] = {
        "suco de laranja",
        "morango fresco",
        "mamao",
        "goiaba vermelha",
        "manga",
        "laranja",
        "brocolis"
    };
    
    for (int i = 0; i < 7; i++) {
        if (strcmp(nome, nomesDosAlimentos[i]) == 0) {
            return valores[i];
        }
    }
    
    return -1; // Valor padrão caso o alimento não seja encontrado
}

void imprimeResultado(int valor){
    
    int valorMedio;
    
    if(valor > 130){
        valorMedio = valor - 130;
        printf("Menos %d mg\n", valorMedio);
    }
    else if(valor < 110){
        valorMedio = 110 - valor;
        printf("Mais %d mg\n", valorMedio);
    }
    else{
         printf("%d mg\n", valor);
    }
    
}

void consumoGeral(int qtddGeral, int qtddAlimento[], const char *nomeAlimento[]) {
    int somaVitaminaC = 0;
    
    for (int i = 0; i < qtddGeral; i++) {
        somaVitaminaC += tabelaDeAlimento(nomeAlimento[i]) * qtddAlimento[i];
    }
    
    imprimeResultado(somaVitaminaC);
}
 
int main() {
    int quantidadeDeAlimento;
    
    //printf("Digite a quantidade de alimento: ");
    scanf("%d", &quantidadeDeAlimento);
    getchar();  // Consumir o caractere de nova linha deixado pelo scanf

    while (quantidadeDeAlimento != 0) {
        int *quantidadeDeCadaAlimento = (int *)malloc(quantidadeDeAlimento * sizeof(int));
        char **nomeDoAlimento = (char **)malloc(quantidadeDeAlimento * sizeof(char *));
        
        for (int i = 0; i < quantidadeDeAlimento; i++) {
            nomeDoAlimento[i] = (char *)malloc(100 * sizeof(char)); // Alocar espaço para o nome
            
            //printf("Digite a quantidade do alimento e o alimento: ");
            int quantidade;
            char linha[100];
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%d %[^\n]", &quantidade, linha);
            quantidadeDeCadaAlimento[i] = quantidade;
            strcpy(nomeDoAlimento[i], linha);

            if (nomeDoAlimento[i][strlen(nomeDoAlimento[i]) - 1] == '\n') {
                nomeDoAlimento[i][strlen(nomeDoAlimento[i]) - 1] = '\0';
            }
        }

        consumoGeral(quantidadeDeAlimento, quantidadeDeCadaAlimento, (const char **)nomeDoAlimento);

        // Liberar memória alocada
        for (int i = 0; i < quantidadeDeAlimento; i++) {
            free(nomeDoAlimento[i]);
        }
        free(nomeDoAlimento);
        free(quantidadeDeCadaAlimento);

        //printf("Digite a quantidade de alimento: ");
        scanf("%d", &quantidadeDeAlimento);
        getchar();  // Consumir o caractere de nova linha deixado pelo scanf
    }

    return 0;
}