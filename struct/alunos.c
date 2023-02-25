#include<stdio.h>
#include<stdlib.h>


typedef struct aluno{ // Criando a struct alunos
    char nome[50];
    int matricula;
    float IRA;
}Aluno;

void imprimir(Aluno *impressao, int nmr_alunos){ // Imprimindo alunos

    int cont;
     for(cont = 0; cont < nmr_alunos; cont++){ // Imprimindo os dados da quantidade de alunos que possui
        printf("O nome do %i aluno é: %s\n" , cont + 1, impressao[cont].nome);
        printf("A matricula do %iº é: %d\n" , cont + 1, impressao[cont].matricula);
        printf("O IRA do %iº é :%f\n" , cont + 1, impressao[cont].IRA);
    }
}

int main(void){
    Aluno *vetor_aluno; // Declarando variaveis
    int qntd_alunos,cont;
    printf("Digite o numero de alunos que voce deseja cadastrar:\n");
    scanf("%i", &qntd_alunos);
    vetor_aluno = (Aluno*) malloc(qntd_alunos * sizeof(Aluno)); // Alocando o vetor_alunos
    if (vetor_aluno == NULL)
    {
        exit(1);
    }
    
    for(cont = 0; cont < qntd_alunos; cont++){ // Preechendo o vetor_alunos com os dados que a struct possui
        printf("Digite o nome do %iº do aluno:\n " , cont + 1);
        scanf(" %[^\n]s" , vetor_aluno[cont].nome);
        printf("Digite a matricula do %iº: \n", cont + 1);
        scanf("%d" , &vetor_aluno[cont].matricula);
        printf("Digite o IRA do %iº do aluno:\n " , cont + 1);
        scanf("%f", &vetor_aluno[cont].IRA);
    }

    imprimir(vetor_aluno, qntd_alunos); /// Passando os parametros da função

    free(vetor_aluno); // Desalocando a memoria
    
    return(0);
}
