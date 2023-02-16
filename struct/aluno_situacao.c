#include <stdio.h>

typedef enum situacao
{
    ativo,
    inativo,
    trancado
    
} Situacao;

typedef struct aluno
{
    char nome[50];
    int matricula;
    char curso[50];
    Situacao opcao; 

} Aluno;

int main(void)
{
    Aluno aluno;
    printf("Informe o nome do aluno\n");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe a matricula:\n");
    scanf("%d", &aluno.matricula);
    printf("Informe o curso do aluno:\n");
    scanf(" %[^\n]s", aluno.curso);

    printf("Digite\n 0 - Ativo\n 1 - Inativo\n 2 - Trancado");
    scanf("%d", (int*)&aluno.opcao);

    if(aluno.opcao == ativo)
    {
    
        printf("O nome do aluno é :%s \t", aluno.nome);
        printf("O curso do aluno é: %s \t", aluno.curso);
        printf("O a matricula do aluno é:%d \t", aluno.matricula);
        printf("A situacao do aluno é: Ativo");

    }

    else if(aluno.opcao == inativo)
    {
       
        printf("O nome do aluno é :%s \t", aluno.nome);
        printf("O curso do aluno é: %s \t", aluno.curso);
        printf("O a matricula do aluno é:%d \t", aluno.matricula);
        printf("A situacao do aluno é: Inativo");
    
    }

    else
    {
        
        printf("O nome do aluno é :%s \t", aluno.nome);
        printf("O curso do aluno é: %s \t", aluno.curso);
        printf("O a matricula do aluno é:%d \t", aluno.matricula);
        printf("A situacao do aluno é: Trancado");

    }

    return (0);
}
