#include<stdio.h>
#include<stdlib.h>

int main(void){
    int tamanho = 10,i;
    int * vetor;
    vetor = (int*) malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro!");
        exit(1);

    }

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
    }

    for (i = 0; i < tamanho; i++)
    {
       
        printf("%i \t", vetor[i]);

    }

    free(vetor);

    return(0);
}
