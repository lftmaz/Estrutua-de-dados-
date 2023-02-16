#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
    int numero_questoes = 0, i, j, acertos, aprovado = 0;
    float porcetagem_aprovacao = 0, vetor_alunos[10], valor_questoes = 0;

    printf("Quantas questoes possui a prova?");
    scanf("%d", &numero_questoes);

    valor_questoes = 10/numero_questoes;

    char *gabarito = (char *) malloc(numero_questoes * sizeof(char));
    if (gabarito == NULL)
    {
        exit(1);
    }

    printf("Digite o gabarito da prova:\n");
    for (i = 0; i < numero_questoes; i++)
    {
        scanf(" %s" , &gabarito[i]);
    }

    char **aluno = (char **)malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        aluno[i] = (char *)malloc(numero_questoes * sizeof(char));
    }

    for (i = 0; i < 10; i++)
    {
        printf("Digite as respostas do %d aluno: \n" , i + 1);
        for (j = 0; j < numero_questoes; j++)
        {
            scanf(" %s", &aluno[i][j]);
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < numero_questoes; j++)
        {
            if (aluno[i][j] == gabarito[j])
            {
                acertos++;
            }
        }
        vetor_alunos[i] = 0;
        vetor_alunos[i] = acertos * valor_questoes;
        acertos = 0;

        printf("Nota do %i aluno: %.2f \n" , i +1 , vetor_alunos[i]);
    }

    for(i = 0; i < 10; i++){
        if(vetor_alunos[i] >= 6.0){
            aprovado++;
        }
        
    }

    porcetagem_aprovacao = (aprovado/10) * 100;

    printf("A taxa de aprovação é: %.2f \n" , porcetagem_aprovacao);

    for (i = 0; i < 10; i++)
    {
        free(aluno[i]);
    }
    free(aluno);
    
    return (0);
}
