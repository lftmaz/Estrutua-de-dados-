#include <stdio.h>
#include <stdlib.h>

int **criaMatrizFloat(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    int linha;
    for (linha = 0; linha < linhas; linha++)
    {
        matriz[linha] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

int main(void)
{
    int linhas = 3;
    int colunas = 3;
    int **matriz = criaMatrizFloat(linhas, colunas);
    
    int i,j;
    printf("Digite os valores para matriz: \n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            matriz[i][j] = i * 3 + j;
        }
    }

    for (i = 0; i < linhas; i++)
    {
        printf("\n");

        for (j = 0; j < colunas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
    }

    for (i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}