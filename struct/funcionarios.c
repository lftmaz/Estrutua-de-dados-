#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario // Declarando a struct
{
    char nome[50];
    char cargo[50];
    float salario;
    int identificador;
} Funcionario;

void dados(Funcionario *funcionario, int numero_funcionarios) // Função para coletar os dados de cada funcinario
{
    int i;
    for(i = 0;i < numero_funcionarios; i++)
    {
    printf("Digite o nome do funcionario:\n");
    scanf(" %[^\n]s", funcionario[i].nome);
    printf("Digite o nome do cargo\n");
    scanf(" %[^\n]s", funcionario[i].cargo);
    printf("Digite o salario do funcionario:\n");
    scanf("%f", &funcionario[i].salario);
    printf("Digite o identificador do funcionario:\n");
    scanf("%d", &funcionario[i].identificador);
    }
}

void imprimir(Funcionario *funcionario_impresso, int numero_funcionarios) // Função para imprimir os dados de cada funcionario
{
    int i;
    for(i = 0; i < numero_funcionarios; i++)
    {
    printf("O nome do funcionario e: %s\n", funcionario_impresso[i].nome);
    printf("O cargo do funcionario e: %s\n", funcionario_impresso[i].cargo);
    printf("O salario do funcionario e: %.2f\n", funcionario_impresso[i].salario);
    printf("O identificador do funcionario e: %d\n", funcionario_impresso[i].identificador);
    }
}

void altera_salario(Funcionario *funcionario_salario) // Alterando o salario do primeiro funcionario para um novo escolhido pelo usuario
{
    printf("Digite o seu novo salario:\n");
    scanf("%f", &funcionario_salario->salario);
}

void maior_menor(Funcionario *funcionario_maiormenor, int numero_funcionarios) // Função para verificar o maior e o menor salario
    int i;
    float salario = 0, salario_menor = 99999999;
    int cargo = 0,cargomenor = 0;
    for (i = 0; i < numero_funcionarios; i++)// Fazendo a verificação para saber quem possui o maior e menor salario e armazenando o cargo
    {
        if (funcionario_maiormenor[i].salario > salario)
        {
            salario = funcionario_maiormenor[i].salario;
            cargo = i;
        }
        else if (funcionario_maiormenor[i].salario < salario_menor)
        {
            salario_menor = funcionario_maiormenor[i].salario;
            cargomenor = i;
        }
    }
    printf("Cargo %s\n" , funcionario_maiormenor[cargo].cargo);
    printf("Maior Salario %.2f\n" ,salario);
    printf("Cargo %s\n" , funcionario_maiormenor[cargomenor].cargo);
    printf("Menor Salario %.2f\n" , salario_menor);
}

int main(void)
{
    Funcionario *funcionari; // Declarando variaveis
    int qntd_funcionarios;
    printf("Digite o numero de funcionarios:\n "); // Coletando a quantidade de funcionarios
    scanf("%d", &qntd_funcionarios);

    funcionari = (Funcionario *)malloc(qntd_funcionarios * sizeof(Funcionario)); // Alocando funcionarios
    // Passando parâmetro das funções
    dados(funcionari, qntd_funcionarios);
    imprimir(funcionari, qntd_funcionarios);
    altera_salario(funcionari);
    maior_menor(funcionari, qntd_funcionarios);

    free(funcionari); // Liberando a memoria
    return (0);
}
