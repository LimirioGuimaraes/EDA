#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *CriarBOW(FILE *bow, FILE *trA, FILE *dicionario, char nomeArquivo[10], int *cont){
     char ch[50], palavra[50];
     int i, j = 0, k;
     //Abertura do arquivo
     bow = fopen(nomeArquivo, "w+");
     //Cópia do arquivo dicionário em BOW
     while(fscanf(dicionario, "%s", ch) != EOF){
         //voltar trA para o início do arquivo em todo incício de laço
         rewind(trA);
         //Zerar o i em todo inicio de laço
         i = 0;
         while(fscanf(trA, "%s", palavra) != EOF){
             //Somente para conferir variáveis palavra e ch
             /*printf("%s\n", palavra);
             printf("%s\n", ch);*/
             if (strcmp(palavra,ch) == 0){
                 i++;
             }
         }
         //Colocando as palavras contidas em dicionário dentro do BOW
         fputs(ch,bow);
         fprintf(bow, " %d\n", i);
         cont[j] = i;
         /*Print para conferir conteúdo do contA ou contB
         printf("%d ", cont[j]);*/
         j++;
     }

     //Lógica para comparação de dicionário em TRA

     //checagem do ponteiro e mensagem de confirmação
     if (bow == NULL){
         printf("\nFalha na criação ou no acesso ao arquivo...\n");
     } else {
         /*Somente tirar o comentário para conferir a passagem do ponteiro
         (vide main.c)
         printf("\n%p\n",bow);*/
         printf("\nO arquivo %s foi criado!\n\n", nomeArquivo);
     }

     //Voltar os ponteiros para o início dos arquivos
     rewind(bow);
     rewind(dicionario);
     return bow;
}
