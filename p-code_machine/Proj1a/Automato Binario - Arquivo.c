#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE* arquivo;
	char *binario, *vet, caractere, token; 
	int num_car = 0, i = 0, aux = 0; 
    
	arquivo = fopen("arquivo.txt", "r");
    
    while((caractere=fgetc(arquivo)) != EOF) 
        num_car++;
    
    rewind(arquivo);
    binario = (char*) calloc(num_car+1, sizeof(char));
    vet = (char*)calloc(num_car+1, sizeof(char));
    
    while((caractere = fgetc(arquivo)) != EOF){
        binario[i] = caractere; 
        i++;
    }

   	fclose(arquivo);
    
    i = 0;
    
    token = binario[i];    
    goto e0;

    e0:
        if(token == '0'){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else if (token == '1'){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else goto ERRO;

    e1:
        token = binario[i];  
        if(token == '0'){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else if (token == '1'){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else goto FIM;

    ERRO:
        printf("Token Incorreto!!\n");

    FIM:
        aux = i;
        for(i = 0; i < aux; i++)
            printf("%c", vet[i]);
        printf("\n");
    return 0;
}
    