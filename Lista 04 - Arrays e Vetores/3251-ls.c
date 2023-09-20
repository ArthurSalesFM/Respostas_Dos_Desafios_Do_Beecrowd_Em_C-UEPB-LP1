/******************************************************************************

Você está implementando um sistema operacional e agora precisa escrever um programa para listar arquivos em um diretório: ‘ls’. 
Você deseja que o usuário possa listar apenas os arquivos que correspondem a um determinado padrão que pode incluir curingas (*), por exemplo *.c. 
Um curinga corresponde a zero ou mais caracteres de qualquer tipo.

Entrada
A primeira linha contém uma string P, contendo de 1 a 100 caracteres 'a' - 'z', '*' e '.' Este é o padrão. 
A segunda linha contém um inteiro N, 1 ≤ N ≤ 100, que é o número de arquivos no diretório. Em seguida, 
segue N linhas contendo os nomes dos arquivos no diretório. Cada linha é uma string contendo de 1 a 100 caracteres 'a' - 'z' e '.'.

Saída
A saída deve consistir nos nomes de arquivos que correspondem ao padrão, P, cada um em sua própria linha, na mesma ordem em que foram dados como entrada.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int correspondePadrao(const char padrao[], const char nomeArquivo[]) {
    int i = 0, j = 0;
    int indiceAsteriscoPadrao = -1;
    int indiceAsteriscoNomeArquivo = -1;

    while (1) {
        
        if (padrao[i] == '?' || padrao[i] == nomeArquivo[j]) {
            i++;
            j++;
        } 
        else if (padrao[i] == '*') {
            indiceAsteriscoPadrao = i;
            indiceAsteriscoNomeArquivo = j;
            i++;
        } 
        else if (indiceAsteriscoPadrao != -1) {
            j = indiceAsteriscoNomeArquivo + 1;
            i = indiceAsteriscoPadrao + 1;
            indiceAsteriscoNomeArquivo++;
        } 
        else {
            return 0;
        }

        if (padrao[i] == '\0' && nomeArquivo[j] == '\0') {
            return 1;
        } 
        else if (nomeArquivo[j] == '\0') {
            return 0;
        }
    }
}

int main() {
    char padrao[101];
    int n;

    scanf("%s", padrao);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char nomeArquivo[101];
        scanf("%s", nomeArquivo);

        if (correspondePadrao(padrao, nomeArquivo)) {
            printf("%s\n", nomeArquivo);
        }
    }
    return 0;
}