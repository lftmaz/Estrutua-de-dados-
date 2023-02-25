#include <stdio.h>
#include <stdlib.h>

typedef struct pessoas // Declarando a struct
{
    char nome_pessoa[60];;
    int idade;
    int identificador;
} Pessoas;

void dados(Pessoas *pessoas, int numero_pessoas) // Coletando os dados das pessoas
{
    int i;
    for(i = 0;i < numero_pessoas; i++)
    {
    printf("Digite o nome da pessoa:\n");
    scanf(" %[^\n]s", pessoas[i].nome_pessoa);
    printf("Digite o idade da pessoa:\n");
    scanf("%d", &pessoas[i].idade);
    printf("Digite o identificador do funcionario:\n");
    scanf("%d", &pessoas[i].identificador);
    }
}

void imprimir(Pessoas *pessoa_impresso, int numero_pessoas) // Imprimindo os dados das pessoas
{
    int i;
    for(i = 0; i < numero_pessoas; i++)
    {
    printf("O nome da pessoa e: %s\n", pessoa_impresso[i].nome_pessoa);
    printf("A idade da pessoa e: %.2d\n", pessoa_impresso[i].idade);
    printf("O identificador da pessoa e: %d\n", pessoa_impresso[i].identificador);
    }
}

void altera_idade(Pessoas *pessoa_idade) // Alternado a idade da primeira pessoa
{
    printf("Digite o sua nova idade:\n");
    scanf("%d", &pessoa_idade->idade);
}

void maior_menor(Pessoas *pessoa_maiormenor, int numero_pessoas) // Verificando qual pessoa tem a maior e menor idade e salvando o nome  dela
{
    int i;
    int idade = 0, idade_menor = 99999999;
    int nome = 0,nome_menor = 0;
    for (i = 0; i < numero_pessoas; i++)
    {
        if (pessoa_maiormenor[i].idade > idade)
        {
            idade = pessoa_maiormenor[i].idade;
            nome = i;
        }
        if (pessoa_maiormenor[i].idade < idade_menor)
        {
            idade_menor = pessoa_maiormenor[i].idade;
            nome_menor = i;
        }
    }
    printf("Nome %s\n" , pessoa_maiormenor[nome].nome_pessoa);
    printf("Maior Idade %d\n" ,idade);
    printf("Nome %s\n" , pessoa_maiormenor[nome_menor].nome_pessoa);
    printf("Menor Idade %d\n" , idade_menor);
}

int main(void)
{
    Pessoas *pessoa; // Declarando variaveis
    int qntd_pessoas;
    printf("Digite o numero de pessoas:\n "); // Coletando o numero de pessoas
    scanf("%d", &qntd_pessoas);

    pessoa = (Pessoas *)malloc(qntd_pessoas * sizeof(Pessoas)); // Alocando o vetor pessoas
    // Acessando as funções
    dados(pessoa, qntd_pessoas);
    imprimir(pessoa, qntd_pessoas);
    altera_idade(pessoa);
    maior_menor(pessoa, qntd_pessoas);

    free(pessoa); // Liberando a memoria
    return (0);
}
