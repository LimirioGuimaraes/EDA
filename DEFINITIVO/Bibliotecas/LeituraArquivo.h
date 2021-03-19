#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *LeituraArquivo(FILE *Arquivo){
     char nArquivo[20];

     //Função de leitura do dicionário
     printf("\nDigite o nome do arquivo (Máximo de 20 caracteres): ");
     scanf("%s", nArquivo);
     //Abertura do arquivo dicionário
     Arquivo = fopen(nArquivo, "r");
     //checagem do ponteiro e mensagem de confirmação
     if (Arquivo == NULL){
         printf("\nNome não válido...\n");
     } else {
         printf("\nO arquivo %s foi selecionado!\n\n", nArquivo);
         
     }

     return Arquivo;
}
