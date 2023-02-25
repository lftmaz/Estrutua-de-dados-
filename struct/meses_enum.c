#include<stdio.h>
#include<stdlib.h>

typedef enum meses{ // Declarando enum
    zero,
    janeiro,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
} Meses;

typedef struct data // Declarando a struct data 
{
    int dia;
    int ano;
    Meses mes;
}Data;

int main(void){
    Data data; // Declarando a variavel
    printf("Digite o dia:\n");
    scanf("%d" , &data.dia);
    printf("Digite:\n 1 - Janeiro\n 2 - Fevereiro\n 3 - Marco\n 4 - Abril\n 5 - Maio\n 6 - Junho\n 7 - Julho\n 8 - Agosto\n 9 - Setembro\n 10 - Outubro\n 11 - Novembro\n 12 - Dezembro\n");
    scanf("%d" , (int*)&data.mes);
    printf("Digite o ano:\n");
    scanf("%d" , &data.ano); // Coletando os dados da struct e do enum
    switch (data.mes) // Verificando qual a condição o enum entrar e exibindo a data
    {
    case 1:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;
    case 2:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;  
    case 3:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;        
    case 4:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;  
    case 5:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;  
    case 6:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;   
    case 7:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;  
    case 8:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;  
    case 9:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
    case 10:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;
    case 11:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;   
    case 12:
        printf("%d/0%d/%d" ,data.dia, data.mes,data.ano);
        break;        
    default:
        printf("Erro!");
        exit(1);
        break;
    }
return (0);
}
