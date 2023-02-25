#include<stdio.h>

typedef union documentos // Declarando a union
{
    int cpf;
    int sus;
    int rg;
}Documentos;

typedef struct aluno // Declarando a struct
{
    char nome[50];
    int matricula;
    Documentos doc;
}Aluno;

void imprimir(Aluno aluno , int caso){ // Funcao para imrprimir os dados do alunos
    printf("Nome do aluno: %s\n" , aluno.nome);
    printf("Sua matricula: %d \n" , aluno.matricula);
    if( caso == 1){
    printf("Seu documento: %d" , aluno.doc.cpf);
    }
    else if( caso == 2){
    printf("Seu documento: %d" , aluno.doc.rg);
    }
    else{
    printf("Seu documento: %d" , aluno.doc.sus);
    }
}

int main(void)
{
    Aluno *aluno; // Declarando variaveis
    int opcao;
    printf("Informe o nome do aluno\n"); // Colhendo os dados dos alunos
    scanf(" %[^\n]s" , aluno->nome);
    printf("Informe a matricula:\n");
    scanf("%d", &aluno->matricula);

    printf("Informe o documento\n 1 - CPF\n 2 - RG\n 3 - SUS \nSua escolha:"); // Colhendo a opocao de documento
    scanf("%d" , (int*) &opcao);

    switch (opcao) //  Verificando qual a opcao foi escolhida e preenchendo a union
    {
    case 1:
        printf("Informe o CPF:\n");
        scanf("%d" , &aluno->doc.cpf);
        imprimir(*aluno,1);
        break;
    
    case 2:
        printf("Informe o RG:\n");
        scanf("%d" , &aluno->doc.rg);
        imprimir(*aluno,2);
        break;
    
    case 3:
        printf("Informe o SUS:\n");
        scanf("%d" , &aluno->doc.sus);
        imprimir(*aluno,3);
        break;
    
    default:
        printf("Opcao Invalida!\n");
        break;
    }

    

    return(0);
}
