#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Difinindo turmas e vagas
#define MAX_TURMAS 2
#define MAX_VAGAS 4

typedef struct aluno // Definindo a struct aluno
{
    int mat;
    char nome[81];
    float nota[3];
    float media;
} Aluno;

typedef struct turmas // Definindo a struct turmas
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];
} Turmas;

Turmas *cria_turma(char id) // Função para criar turmas
{
    int i;
    Turmas *turma = (Turmas *)malloc(sizeof(Turmas)); 
    turma->id = id;
    turma->vagas = MAX_VAGAS;
    for (i = 0; i < MAX_VAGAS; i++)
    {
        turma->alunos[i] = NULL;
    }
    printf("Turma %c criada com sucesso\n", turma->id);
    return turma;
    // Preenchendo a estrutura turma
}

void matricula_aluno(Turmas *turma, int matricula, char *nome) // Matriculando alunos
{
    int i, j;
    if (turma->vagas == 0) // Verificando se há vagas
    {
        printf("Não há vagas:\n");
    }
    else
    {
        for (i = 0; i < MAX_VAGAS; i++)
        {
            turma->alunos[i] = (Aluno *)malloc(sizeof(Aluno));
            if (turma->alunos[i] = NULL)
            {
                exit(1);
            }

            for (i = 0; i < MAX_VAGAS; i++)
            {
                if (turma->alunos[i] == NULL)
                {
                    turma->alunos[i]->mat = matricula;
                    strcpy(turma->alunos[i]->nome, nome);
                    for (j = 0; j < 3; j++)
                    {
                        turma->alunos[i]->nota[j] = 0;
                    }
                    turma->alunos[i]->media = 0;
                } // Preenchendo os dados de cada aluno
            }
            turma->vagas--;
        } // Matriculando o aluno
    }
    printf("Aluno matriculado com  sucesso!");
}
void lancar_notas(Turmas *turma) // Atribuir notas aos alunos
{
    int i, j;
    for (j = 0; j < MAX_VAGAS; j++)
    {
        if (turma->alunos[j] != NULL)
        {
            for (i = 0; i < 3; i++)
            {
                printf("Digite a nota %d:", i + 1);
                scanf(" %f", &turma->alunos[j]->nota[i]); // Atibuindo notas
            }
            turma->alunos[j]->media = (turma->alunos[i]->nota[0] + turma->alunos[i]->nota[1] + turma->alunos[i]->nota[2]) / 3; // Calculando a media
        }
    }
} 

void imprime_turmas(Turmas **turmas, int n) // Imprimindo as turmas criadas
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
    }

}

void imprime_alunos(Turmas *turma) // Imprimindo os dados dos alunos de cada turma
{
    int i;
    for (i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Nome: %s\n", turma->alunos[i]->nome);
            printf("Media:%f\n", turma->alunos[i]->media);
        }
    }
}

void procura_turma(Turmas **turma, char id, int n) // Procurando uma turma especifica
{
    int i;
    for (i = 0; i <= n; i++)
    {
        if (turma[i]->id == id)
        {
            printf("Turma %c - %d vagas disponiveis\n", turma[i]->id, (int *)turma[i]->vagas); // Exibindo a turma encontrada
            break;
        }
        else if (i == n)
        {
            printf("Não há turmas cadastradas!\n");
        }
    }
}

int main(void)
{
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas! Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.");
    int opcao = 0, cont = 0, matricula, i, salva_turma; // Declarando variaveis
    char id, nome[81];
    Turmas **turma = (Turmas **)malloc(MAX_TURMAS * sizeof(Turmas *)); // Alocando turma
    if (turma == NULL)
    {
        exit(1);
    }

    while (opcao != 7) // Condição de repetição
    {
        printf("Menu:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - BUscar Turma\n7 - Sair \n");
        scanf("%d", &opcao); // Recebendo a condicao de repetição
        switch (opcao)
        {
            // Criando a opcao 1
        case 1:
            if (cont < MAX_TURMAS)
            {
                printf("Criando nova turma...\n");
                printf("Digite o ID da turma:");
                scanf(" %c", &id);
                turma[cont] = cria_turma(id); //Passando o id para criação da turma
                cont++;
            }
            else
            {
                printf("Você atingiu o número máximo de turmas!\n");
            }
            break;

            // Criando a opcao 2
        case 2:
            printf("Listando turmas...\n");
            imprime_turmas(turma, cont); // Passando o indice da turma para exibir
            break;
            // Criando opcao 3
        case 3:
            printf("Matriculando aluno...\n");
            printf("Digite o ID da turma\n");
            scanf(" %c", &id);
            for (i = 0; i < cont; i++)
            {
                if (turma[i]->id == id) // Verificando qual a turma vai acessar
                {
                    salva_turma = i;
                }
            }
            // Lendo os dados do aluno
            printf("Digite a matricula do aluno:\n");
            scanf("%d", &matricula);
            printf("Digite o nome do aluno:\n");
            scanf(" %[^\n]s", (char *)&nome); 
            matricula_aluno(turma[salva_turma], matricula, nome);
            break;
        // Criando opção 4
        case 4:
            printf("Lancado notas...\n"); 
            printf("Digite o ID da turma:\n");
            scanf(" %c", &id);
            for (i = 0; i < cont; i++)
            {
                if (turma[i]->id == id)
                {
                    salva_turma = i;
                }
            }
            lancar_notas(turma[salva_turma]);
            break;
        // Criando a opcao 5
        case 5:
            printf("Listando alunos...\n");
            printf("Digite o ID da turma:\n");
            scanf(" %c", &id);
            for (i = 0; i < cont; i++)
            {
                if (turma[i]->id == id)
                {
                    salva_turma = i;
                }
            }
            imprime_alunos(turma[salva_turma]); // Listando alunos
            break;
                
        // Criando a opção 6        
        case 6:
            printf("Digite o ID da turma:\n");
            scanf(" %c", &id);
            procura_turma(turma, id, cont); // Procurando a turma 
            break;
        default:
            break;
        }
    }
    for (i = 0; i < MAX_TURMAS; i++) // Liberando a memoria
    {
        free(turma[i]);
    }
    free(turma);
    return (0);
}
