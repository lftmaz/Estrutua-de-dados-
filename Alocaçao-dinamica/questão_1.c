#include<stdio.h>
#include<stdlib.h>

int main(void){
    int tamanho = 10,i; // Declarando variaveis
    int * vetor;
    vetor = (int*) malloc(tamanho * sizeof(int)); //Alocando memoria
    if (vetor == NULL)
    {
        printf("Erro!");
        exit(1);

    }

    for (i = 0; i < tamanho; i++) // Preenchendo vetor com o indice
    {
        vetor[i] = i;
    }

    for (i = 0; i < tamanho; i++) // Exibindo o vetor
    {
       
        printf("%i \t", vetor[i]);

    }

    free(vetor); // Desocupando a memoria

    return(0);
}
