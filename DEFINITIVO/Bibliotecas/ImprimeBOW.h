#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimeBOW(int *conta, int *contb, FILE *dicionario){
    int i = 0; /*O(1)*/
    char palavras[50]; /*O(1)*/
    //Percorre os vetores contA e contB, imprime a quantidade de aparições da palavra
    while(fscanf(dicionario, "%s", palavras) != EOF) /*O(N)*/ {
        //Verifica se ambos os vetores são diferentes de 0 para a posição i
        if(conta[i] != 0 || contb[i] != 0) /*O(1)*/ {
            printf("%s", palavras); /*O(1)*/
            printf("\t\t%d\t\t%d\n", conta[i], contb[i]); /*O(1)*/
        }
        i++; /*O(1)*/
    }

}
