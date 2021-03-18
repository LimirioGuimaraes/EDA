#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *PreencherBOW(FILE *bagow, FILE *dici){
    char palavra[100];

    while(fgets(palavra, 100, dici) != NULL){
        fputs(palavra, bagow);
    }

    return bagow;
}
