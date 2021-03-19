#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *LeituraArquivo(FILE *Arquivo){
     char nArquivo[20]; /*O(1)*/

     //Função de leitura do dicionário
     printf("\nDigite o nome do arquivo (Máximo de 20 caracteres): "); /*O(1)*/
     scanf("%s", nArquivo); /*O(1)*/
     //Abertura do arquivo dicionário
     Arquivo = fopen(nArquivo, "r"); /*O(1)*/
     //checagem do ponteiro e mensagem de confirmação
     if (Arquivo == NULL) /*O(1)*/ {
         printf("\nNome não válido...\n"); /*O(1)*/
     } else /*O(1)*/ {
         printf("\nO arquivo %s foi selecionado!\n\n", nArquivo); /*O(1)*/

     }

     return Arquivo; /*O(1)*/
}
