#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PreencherBOW.h"

 FILE *CriarBOW(FILE *bow, FILE *dict){
     char ch[50];
     //Abertura do arquivo
     bow = fopen("bowA.txt", "w+");
     //Cópia do arquivo dicionário em BOW
     while(fgets(ch, 50, dict) != NULL){
         fputs(ch,bow);
     }

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
