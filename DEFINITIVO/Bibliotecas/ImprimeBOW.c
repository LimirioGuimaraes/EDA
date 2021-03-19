#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimeBOW(int *conta, int *contb, FILE *dicionario){
    int i = 0;
    char palavras[50];
    //Percorre os vetores contA e contB, imprime a quantidade de aparições da palavra
    while(fscanf(dicionario, "%s", palavras) != EOF){
        //Verifica se ambos os vetores são diferentes de 0 para a posição i
        if(conta[i] != 0 || contb[i] != 0){
            printf("%s", palavras);
            printf("\t\t%d\t\t%d\n", conta[i], contb[i]);
        }
        i++;
    }

}
