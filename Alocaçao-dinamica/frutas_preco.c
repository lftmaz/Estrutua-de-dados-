#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void imprimir(char **nome, float *valor, int numero_frutas)
{
    int i;
    for(i = 0; i < numero_frutas; i++)
    {
        printf("A sua fruta e: %s\n", nome[i]);
        printf("O valor da fruta e: %.2f" , valor[i]);
    }
}

int main(void)
{
    int qnt_frutas, linha;
    printf("Digite o numero de frutas:");
    scanf("%d", &qnt_frutas);
    int tamanho[qnt_frutas];
    char **frutas = (char **)malloc(qnt_frutas * sizeof(char *));
    if (frutas == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    for (linha = 0; linha < qnt_frutas; linha++)
    {
        frutas[linha] = (char *)malloc(50 * sizeof(char));
    }

    float *preco = (float *)malloc(qnt_frutas * sizeof(float));
    if (preco == NULL)
    {
        exit(1);
    }

    for (linha = 0; linha < qnt_frutas; linha++)
    {
        printf("Informe as frutas e o seu valor:");
        scanf(" %s %f", (char *)frutas[linha] , &preco[linha]);
        tamanho[linha] = strlen(frutas[linha]);
        frutas[linha] = (char *)realloc(frutas[linha],tamanho[linha] * sizeof(char));
        

    }
    
    imprimir(frutas,preco,qnt_frutas);

    for( linha = 0; linha < qnt_frutas; linha++){
        free(frutas[linha]);
    }
    free(frutas);
    free(preco);

    return (0);
}