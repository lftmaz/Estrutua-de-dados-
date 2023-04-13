#include <stdlib.h>
#include <stdio.h>
#include "listas.c"

int maior(Lista *l, int termo_compara)
{
    Lista *p;
    int maiores = 0;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info > termo_compara)
        {
            maiores++;
        }
    }
    return maiores;
}

Lista *ultimo(Lista *l)
{
    Lista *p , *ultimo;
    for (p = l; p != NULL; p = p->prox)
    {
        if(p->prox == NULL){
            ultimo = p;
        }
    }
    return ultimo;
}

int main(void)
{
    Lista *l ,*resultado_ultimo;
    int i = 0, numero_termos = 0, termo = 0, comparacao = 0, resultado_maior = 0;
    printf("Digite o numero de termos que a lista tera:\n");
    scanf("%d", &numero_termos);
    l = lst_criar();
    for (i = 0; i < numero_termos; i++)
    {
        printf("Digite o %i termo: \n", i + 1);
        scanf("%d", &termo);
        l = lst_insere(l, termo);
    }
    printf("Qual valor deve ser comparado? ");
    scanf("%d", &comparacao);
    resultado_maior = maior(l, comparacao);
    printf("Numero de valores maior que: %d = %d\n", comparacao, resultado_maior);
    resultado_ultimo = ultimo(l);
    printf("Ultimo termo da lista: %d" , resultado_ultimo->info);
    return (0);
}
