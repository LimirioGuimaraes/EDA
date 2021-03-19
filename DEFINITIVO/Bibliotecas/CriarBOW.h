#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *CriarBOW(FILE *bow, FILE *tr, FILE *dicionario, char nomeArquivo[10], int *cont){
     char ch[50], palavra[50]; /*O(1)*/
     int i, j = 0; /*O(1)*/
     //Abertura do arquivo
     bow = fopen(nomeArquivo, "w+"); /*O(1)*/
     //Cópia do arquivo dicionário em BOW
     while(fscanf(dicionario, "%s", ch) != EOF) /*O(N^2)*/ {
         //voltar tr para o início do arquivo em todo incício de laço
         rewind(tr); /*O(1)*/
         //Zerar o i em todo inicio de laço
         i = 0;
         while(fscanf(tr, "%s", palavra) != EOF) /*O(N)*/ {

             if (strcmp(palavra,ch) == 0) /*O(1)*/ {
                 i++; /*O(1)*/
             }
         }
         //Colocando as palavras contidas em dicionário dentro do BOW
         fputs(ch,bow); /*O(1)*/
         fprintf(bow, " %d\n", i); /*O(1)*/
         cont[j] = i; /*O(1)*/

         j++; /*O(1)*/
     }

     //Lógica para comparação de dicionário em tr

     //checagem do ponteiro e mensagem de confirmação
     if (bow == NULL) /*O(1)*/ {
         printf("\nFalha na criação ou no acesso ao arquivo...\n"); /*O(1)*/
     } else /*O(1)*/ {

         printf("\nO arquivo %s foi criado!\n\n", nomeArquivo); /*O(1)*/
     }

     //Voltar os ponteiros para o início dos arquivos
     rewind(bow); /*O(1)*/
     rewind(dicionario); /*O(1)*/
     return bow; /*O(1)*/
}
