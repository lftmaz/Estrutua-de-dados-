#include <stdio.h>
#include <stdlib.h>

int mapa
{
    // declarando variaveis
    int linhas, colunas, i, j, costa = 0;
    printf("Insira a quantidade de linhas: ");
    scanf("%d", &linhas);
    printf("Insira a quantidade de colunas: ");
    scanf("%d", &colunas);
    // alocando memoria dinamicamente
    char **mapa = (char **)malloc(linhas * sizeof(char *));
    if (mapa == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    for (i = 0; i < linhas; i++)
    {
        mapa[i] = (char *)malloc(colunas * sizeof(char));
    }
    for (i = 0; i < linhas; i++)
    {
        scanf(" %s", mapa[i]);
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            // verificando se é costa
            if (mapa[i][j] == '#')
            {

                if (i == 0 || mapa[i - 1][j] == '.')
                {
                    costa++;
                }
                else if (i == linhas - 1 || mapa[i + 1][j] == '.')
                {
                    costa++;
                }
                else if ((j == 0 || mapa[i][j - 1] == '.'))
                {
                    costa++;
                }
                else if (j == colunas - 1 || mapa[i][j + 1] == '.')
                {
                    costa++;
                }
            }
        }
    }
    for (i = 0; i < linhas; i++)
    {
        free(mapa[i]); // liberando memoria
    }
    free(mapa);
    printf("%d\n", costa);
    return 0;
}   