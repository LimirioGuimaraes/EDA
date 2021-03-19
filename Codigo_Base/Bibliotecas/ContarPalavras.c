#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarPalavras(FILE *dicionario){
    int N_Palavras = 0;
    char palavra[100];
    //Laço para contagem de palavras dentro do dicionário
    while(fgets(palavra, 100, dicionario) != NULL){

        N_Palavras++;
    }
    //Retornando o ponteiro do dicionário à posição inicial no arquivo
    rewind(dicionario);
    return N_Palavras;
}
