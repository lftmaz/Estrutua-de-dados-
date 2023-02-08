#include<stdio.h>
#include<math.h>


void calcula_hexagono(float lado,float *area,float *perimetro){
    *perimetro = 6*lado;
    *area = ((3 * pow(lado,2))*sqrt(3))/2;
}

int main(void){
    float lado, area,perimetro;
    printf("Digite o tamanho do lado do hexagono:\n");
    scanf("%f" , &lado);
    calcula_hexagono(lado,&area,&perimetro);
    printf("%f\n" , perimetro);
    printf("%f\n" , area);
    return(0);
}
