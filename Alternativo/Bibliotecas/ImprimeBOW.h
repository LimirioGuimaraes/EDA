#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimeBOW(int *conta, int *contb, FILE *dicionario){
    int i = 0;
    char palavras[50];
    while(fscanf(dicionario, "%s", palavras) != EOF){
        printf("%s", palavras);
        printf("\t\t%d\t\t%d\n", conta[i], contb[i]);
        i++;
    }

}
