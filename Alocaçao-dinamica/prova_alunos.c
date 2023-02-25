#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numero_questoes = 0, i, j, acertos = 0, aprovado = 0; // Declarando variaveis
    float porcetagem_aprovacao = 0, vetor_alunos[10], valor_questoes = 0;

    printf("Quantas questoes possui a prova?");
    scanf("%d", &numero_questoes);

    valor_questoes = (float)10 / numero_questoes; // Calculando quanto cada questao vale

    char *gabarito = (char *)malloc(numero_questoes * sizeof(char)); // Alocando a matriz gabarito dinamicamente
    if (gabarito == NULL)
    {
        exit(1);
    }

    printf("Digite o gabarito da prova:\n"); // Obtendo o gabarito
    for (i = 0; i < numero_questoes; i++)
    {
        scanf(" %s", &gabarito[i]);
    }

    char **aluno = (char **)malloc(10 * sizeof(char *)); // Alocando a matriz dos alunos e respostas
    for (i = 0; i < 10; i++)
    {
        aluno[i] = (char *)malloc(numero_questoes * sizeof(char));
    }

    for (i = 0; i < 10; i++)
    {
        printf("Digite as respostas do %d aluno: \n", i + 1); // Obtendo a respotas de cada aluno
        for (j = 0; j < numero_questoes; j++)
        {
            scanf(" %s", &aluno[i][j]);
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < numero_questoes; j++)
        {
            if (aluno[i][j] == gabarito[j]) // Somando os acertos 
            {
                acertos++;
            }
        }
        vetor_alunos[i] = valor_questoes * acertos; // Preenchendo a nota de cada aluno
        acertos = 0;

        printf("Nota do %i aluno: %.2f \n", i + 1, vetor_alunos[i]); // Exibindo a nota de cada aluno
    }

    for (i = 0; i < 10; i++)
    {
        if (vetor_alunos[i] >= 6.0) // Calculando quantos foram aprovados
        {
            aprovado++;
        }
    }

    porcetagem_aprovacao = (aprovado * 100)/10; // Calculando a porcetagem de aprovação

    printf("A taxa de aprovação é: %.2f \n", porcetagem_aprovacao); 

    for (i = 0; i < 10; i++) // Desalocando a memoria 
    {
        free(aluno[i]);
    }
    free(aluno);

    return (0);
}
