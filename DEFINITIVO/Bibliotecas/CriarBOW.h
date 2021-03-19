#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *CriarBOW(FILE *bow, FILE *tr, FILE *dicionario, char nomeArquivo[10], int *cont){
     char ch[50], palavra[50];
     int i, j = 0;
     //Abertura do arquivo
     bow = fopen(nomeArquivo, "w+");
     //Cópia do arquivo dicionário em BOW
     while(fscanf(dicionario, "%s", ch) != EOF){
         //voltar tr para o início do arquivo em todo incício de laço
         rewind(tr);
         //Zerar o i em todo inicio de laço
         i = 0;
         while(fscanf(tr, "%s", palavra) != EOF){

             if (strcmp(palavra,ch) == 0){
                 i++;
             }
         }
         //Colocando as palavras contidas em dicionário dentro do BOW
         fputs(ch,bow);
         fprintf(bow, " %d\n", i);
         cont[j] = i;

         j++;
     }

     //Lógica para comparação de dicionário em tr

     //checagem do ponteiro e mensagem de confirmação
     if (bow == NULL){
         printf("\nFalha na criação ou no acesso ao arquivo...\n");
     } else {

         printf("\nO arquivo %s foi criado!\n\n", nomeArquivo);
     }

     //Voltar os ponteiros para o início dos arquivos
     rewind(bow);
     rewind(dicionario);
     return bow;
}
