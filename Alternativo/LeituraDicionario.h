#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *LeituraDicionario(FILE *dicionario){
     char nDicionario[20];

     //Função de leitura do dicionário
     printf("\nDigite o nome do arquivo dicionário (Máximo de 20 caracteres): ");
     scanf("%s", nDicionario);
     //Abertura do arquivo dicionário
     dicionario = fopen(nDicionario, "r");
     //checagem do ponteiro e mensagem de confirmação
     if (dicionario == NULL){
         printf("\nNome não válido...\n");
         LeituraDicionario(dicionario);
     } else {
         printf("\nAgora o arquivo %s é o dicionário!\n", nDicionario);
         printf("\n%p\n",dicionario);
     }

     return dicionario;
}
