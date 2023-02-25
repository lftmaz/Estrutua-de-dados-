#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sexo_masculino = 0,sexo_feminino = 0, homem_negado = 0,mulher_aprovado = 0, numero = 0 ,i; // Declarando variaveis
    int *vetor_pessoas, *avaliacao;
    float mulheres_porcetagem = 0, homens_porcetagem = 0;

    vetor_pessoas = (int *)malloc(20 * sizeof(int)); // Alocando o vetor pessoas

    if (vetor_pessoas == NULL)
    {
        printf("Erro!");
        exit(1);
    }

    avaliacao = (int*) malloc(20 * sizeof(int)); // Alocando o vetor avaliacao
   
    if (avaliacao == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    

    printf("Digite o numero de pessoas que voce deseja que responda a pesquisa:\n"); // Descobrindo o numero de pessoas que vão responder a pesquisa
    scanf("%d", &numero);

    vetor_pessoas = (int *)realloc(vetor_pessoas,numero * sizeof(int)); // Realocando os dois vetores para a quantidade correta de pessoas
    avaliacao = (int *)realloc(avaliacao,numero * sizeof(int));

    printf("Digite 1, se voce for homem\n");
    printf("Digite 2, se voce for mulher\n");

    for (i = 0; i < numero; i++) // Preenchendo pessoas com os sexos
    {
        scanf("%d", &vetor_pessoas[i]);
    }

    printf("Digite 3, caso voce tenha gostado do produto\n");
    printf("Digite 4, caso voce nao tenha gostado do produto\n");

      for (i = 0; i < numero; i++) // Preenchendo pessoas com as avaliacoes
    {
        scanf("%d", &avaliacao[i]);
    }

    for(i = 0; i < numero; i++){
        if(vetor_pessoas[i] == 1) // Separando os homens que avaliaram negativamente
        {
            sexo_masculino++;
            if (avaliacao[i] == 4)
            {
                homem_negado++; 
            }
            
        }
        else if(vetor_pessoas[i] == 2) // Separando as mulheres que avaliaram positivamente
        {
            sexo_feminino++;
            if (avaliacao[i] == 3)
            {
                mulher_aprovado++;

            }
            
        }
    }

    mulheres_porcetagem =   (mulher_aprovado * 100)/ sexo_feminino; // Calculando a porcetagem de mulheres que aprovaram o produto
    homens_porcetagem =  (homem_negado * 100)/ sexo_masculino; // Calculando a porcetagem de homens que negaram o produto
    
    printf("Porcetagem de mulheres que gostaram do produto: %f\n" , mulheres_porcetagem); // Exibindo as porcetagens
    printf("Porcetagem de homens que nao gostaram do produto: %f\n" , homens_porcetagem);
    
    free(vetor_pessoas); // Liberando a memoria dos vetores
    free(avaliacao);

    return (0);
}
