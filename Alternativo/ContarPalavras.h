#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarPalavras(FILE *dicionario){
    int N_Palavras = 0;
    char palavra[100];

    while(fgets(palavra, 100, dicionario) != NULL){
        /* Para vizualização das palavras
        printf("%s", palavra);*/
        N_Palavras++;
    }

    rewind(dicionario);
    return N_Palavras;
}
