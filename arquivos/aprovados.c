#include<stdio.h>
#include<string.h>

int main(void){
    FILE *arquivo_entrada, *arquivo_saida;
    float nota1, nota2, nota3, media = 0;
    char nome[100], linha[100];

    arquivo_entrada = fopen("entrada_q3.txt" , "rt");
    if(arquivo_entrada == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    arquivo_saida =  fopen("saida_q3.txt" , "wt");
    if(arquivo_saida == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    while (fgets(linha, 100,arquivo_entrada) != NULL){
        sscanf(linha , "%20[^\t] \t%f \t%f \t%f" ,nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3)/3;
        fprintf(arquivo_saida, "%s\t %1.f %s\n" , nome, media,(media>= 7)?"aprovado" : "negado" );
    }   
    
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
      
    }
    
        
