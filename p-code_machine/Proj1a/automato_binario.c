#include <stdio.h>
#include <stdlib.h>


int main() {
    int token = 0, i = 0, aux = 0;
    int *vet = (int*)malloc(sizeof(int));

    scanf("%d", &token);
    goto e0;

    e0:
        if(token == 0){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else if (token == 1){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else goto ERRO;

    e1:
        scanf("%d", &token);
        if(token == 0){
            vet[i] = token;
            i += 1;
            goto e1;
        } 
        else if (token == 1){
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
            printf("%d", vet[i]);
        printf("\n");
        exit(1);

    return 0;
}
