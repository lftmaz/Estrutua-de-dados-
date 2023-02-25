#include<stdio.h>
#include<math.h>


void calcula_hexagono(float lado,float *area,float *perimetro){
    *perimetro = 6*lado;
    *area = ((3 * pow(lado,2))*sqrt(3))/2; // Calculando o perimetro e a area
}

int main(void){
    float lado, area,perimetro; //Declarando variaveis
    printf("Digite o tamanho do lado do hexagono:\n");
    scanf("%f" , &lado);
    calcula_hexagono(lado,&area,&perimetro); //Passando parâmetro
    printf("%f\n" , perimetro);
    printf("%f\n" , area); // Exibindo perimetro e area
    return(0);
}
