#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void imprimir(char **nome, float *valor, int numero_frutas) // Imprimindo o preco e o nome das frutas
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
    int qnt_frutas, linha; // declarando variaveis 
    printf("Digite o numero de frutas:");
    scanf("%d", &qnt_frutas); // Descobrindo o numero de frutas que o usuario deseja
    int tamanho[qnt_frutas];
    char **frutas = (char **)malloc(qnt_frutas * sizeof(char *)); // Alocando a matriz
    if (frutas == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    for (linha = 0; linha < qnt_frutas; linha++)
    {
        frutas[linha] = (char *)malloc(50 * sizeof(char));
    }

    float *preco = (float *)malloc(qnt_frutas * sizeof(float)); // Alocando o preco 
    if (preco == NULL)
    {
        exit(1);
    }

    for (linha = 0; linha < qnt_frutas; linha++)
    {
        printf("Informe as frutas e o seu valor:");
        scanf(" %s %f", (char *)frutas[linha] , &preco[linha]); // Preenchendo a matriz com as frutas e o preco de cada uma
        tamanho[linha] = strlen(frutas[linha]); // Pegando o tamnho das frutas com a funcao strlen
        frutas[linha] = (char *)realloc(frutas[linha],tamanho[linha] * sizeof(char)); // Realocando a string char para conter o mesmo numero de caracteres da fruta
    }
    
    imprimir(frutas,preco,qnt_frutas); // Criando funcao para imprimir

    for( linha = 0; linha < qnt_frutas; linha++){ // Liberando a memoria
        free(frutas[linha]);
    }
    free(frutas);
    free(preco);

    return (0);
}
