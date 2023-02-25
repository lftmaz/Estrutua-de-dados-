#include <stdio.h>

typedef enum situacao // Criando o enum que diz a situaçao do aluno
{
    ativo,
    inativo,
    trancado
    
} Situacao;

typedef struct aluno // Criando a estrutura que diz o que aluno contem
{
    char nome[50];
    int matricula;
    char curso[50];
    Situacao opcao; 

} Aluno;

void imprimir(Aluno aluno){ // Imprimindo os dados do aluno

    if(aluno.opcao == ativo) // Verificando em qual situação o aluno está
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

}

int main(void)
{
    Aluno aluno; // Declando a variavel aluno
    printf("Informe o nome do aluno\n"); // Colhendo os dados das struct
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe a matricula:\n");
    scanf("%d", &aluno.matricula);
    printf("Informe o curso do aluno:\n");
    scanf(" %[^\n]s", aluno.curso);

    printf("Digite\n 0 - Ativo\n 1 - Inativo\n 2 - Trancado\n Sua escolha: "); // Colhendo os dados da enum
    scanf("%d", (int*)&aluno.opcao);

    imprimir(aluno);

    return (0);
}

