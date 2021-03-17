#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarPalavras(FILE *dic){
    int N_Palavras = 0;
    char palavra[100];

    while(fgets(palavra, 100, dic) != NULL){
        /* Para vizualização das palavras
        printf("%s", palavra);*/
        N_Palavras++;
    }

    return N_Palavras;
}
