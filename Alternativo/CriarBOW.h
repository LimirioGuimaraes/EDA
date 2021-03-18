#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 FILE *CriarBOW(FILE *bow, FILE *dict){
     char ch[100];

     bow = fopen("bowA.txt", "w+");
     /*while(( fgets(ch, 100, dict) ) != NULL ){
         fputs(ch, bow);
     }*/

     //checagem do ponteiro e mensagem de confirmação
     if (bow == NULL){
         printf("\nFalha na criação ou no acesso ao arquivo...\n");
     } else {
         /*Somente tirar o comentário para conferir a passagem do ponteiro
         (vide main.c)
         printf("\n%p\n",bow);*/
         printf("\nO arquivo bowA.txt foi criado!\n\n");
     }
     return bow;
}
