#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    char nome[50];
    char cargo[50];
    float salario;
    int identificador;
} Funcionario;

void dados(Funcionario *funcionario, int numero_funcionarios)
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

void imprimir(Funcionario *funcionario_impresso, int numero_funcionarios)
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

void altera_salario(Funcionario *funcionario_salario)
{
    printf("Digite o seu novo salario:\n");
    scanf("%f", &funcionario_salario->salario);
}

void maior_menor(Funcionario *funcionario_maiormenor, int numero_funcionarios)
{
    int i;
    float salario = 0, salario_menor = 99999999;
    int cargo = 0,cargomenor = 0;
    for (i = 0; i < numero_funcionarios; i++)
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
    Funcionario *funcionari;
    int qntd_funcionarios;
    printf("Digite o numero de funcionarios:\n ");
    scanf("%d", &qntd_funcionarios);

    funcionari = (Funcionario *)malloc(qntd_funcionarios * sizeof(Funcionario));

    dados(funcionari, qntd_funcionarios);
    imprimir(funcionari, qntd_funcionarios);
    altera_salario(funcionari);
    maior_menor(funcionari, qntd_funcionarios);

    free(funcionari);
    return (0);
}
