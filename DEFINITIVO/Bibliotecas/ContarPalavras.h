#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarPalavras(FILE *dicionario){
    int N_Palavras = 0; /*O(1)*/
    char palavra[100]; /*O(1)*/
    //Laço para contagem de palavras dentro do dicionário
    while(fgets(palavra, 100, dicionario) != NULL) /*O(N)*/ {

        N_Palavras++; /*O(1)*/
    }
    //Retornando o ponteiro do dicionário à posição inicial no arquivo
    rewind(dicionario); /*O(1)*/
    return N_Palavras; /*O(1)*/
}
