#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sexo_masculino = 0,sexo_feminino = 0, homem_negado = 0,mulher_aprovado = 0, numero = 0 ,i;
    int *vetor_pessoas, *avaliacao;
    float mulheres_porcetagem = 0, homens_porcetagem = 0;

    vetor_pessoas = (int *)malloc(20 * sizeof(int));

    if (vetor_pessoas == NULL)
    {
        printf("Erro!");
        exit(1);
    }

    avaliacao = (int*) malloc(20 * sizeof(int));
   
    if (avaliacao == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    

    printf("Digite o numero de pessoas que voce deseja que responda a pesquisa:\n");
    scanf("%d", &numero);

    vetor_pessoas = (int *)realloc(vetor_pessoas,numero * sizeof(int));
    avaliacao = (int *)realloc(avaliacao,numero * sizeof(int));

    printf("Digite 1, se voce for homem\n");
    printf("Digite 2, se voce for mulher\n");

    for (i = 0; i < numero; i++)
    {
        scanf("%d", &vetor_pessoas[i]);
    }

    printf("Digite 3, caso voce tenha gostado do produto\n");
    printf("Digite 4, caso voce nao tenha gostado do produto\n");

      for (i = 0; i < numero; i++)
    {
        scanf("%d", &avaliacao[i]);
    }

    for(i = 0; i < numero; i++){
        if(vetor_pessoas[i] == 1)
        {
            sexo_masculino++;
            if (avaliacao[i] == 4)
            {
                homem_negado++;
            }
            
        }
        else if(vetor_pessoas[i] == 2)
        {
            sexo_feminino++;
            if (avaliacao[i] == 3)
            {
                mulher_aprovado++;

            }
            
        }
    }

    mulheres_porcetagem =   (mulher_aprovado * 100)/ sexo_feminino;
    homens_porcetagem =  (homem_negado * 100)/ sexo_masculino;
    
    printf("Porcetagem de mulheres que gostaram do produto: %f\n" , mulheres_porcetagem);
    printf("Porcetagem de homens que nao gostaram do produto: %f\n" , homens_porcetagem);
    
    free(vetor_pessoas);
    free(avaliacao);

    return (0);
}
