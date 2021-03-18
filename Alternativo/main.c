#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LeituraArquivo.h"
#include "CriarBOW.h"
#include "ContarPalavras.h"

int sair(){
    printf("Saindo do programa...\n");
}

int main(){

    int seletor = 1, *ContA, *ContB, n_palavras = 0;
    FILE *dicionario, *arquivoA, *bowA;
    char ch;

    dicionario = NULL;

    do {
        printf("\n\tMenu de opções:\n\n");
        printf("1. Selecionar arquivo dicionário\n");
        printf("2. Selecionar texto de referência A\n");
        printf("3. Selecionar texto de referência B\n");
        printf("4. Comparar textos de referência e dicionário\n");
        printf("0. sair\n\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &seletor);
        system ("cls || clear");

        switch (seletor){
            case 1:
                dicionario = LeituraArquivo(dicionario);

                /*Somente tirar o comentário para conferir a passagem do ponteiro
                (Vide LeituraDicionario.h)
                printf("\n%p\n",dicionario);*/

                n_palavras = ContarPalavras(dicionario);

                /* Para vizualização do número de palavras
                printf("\n%d\n", n_palavras);*/

                ContA = (int*) malloc(n_palavras*sizeof(int));
                ContB = (int*) malloc(n_palavras*sizeof(int));

                /*Somente tirar o comentário para conferir os endereços de memória utilizados
                printf("\n%p  |  %p\n", ContA, ContB);*/
                break;
            case 2:
                arquivoA = LeituraArquivo(arquivoA);
                /*Somente tirar o comentário para conferir os endereços de memória utilizados
                printf("\n%p\n", arquivoA);*/

                bowA = CriarBOW(bowA, dicionario);

                /*Somente tirar o comentário para conferir a passagem do ponteiro
                (Vide CriarArquivo.h)
                printf("\n%p\n",bowA);*/
                break;
            case 3:
                printf("\nVocê selecionou a opção 3\n");
                break;
            case 4:
                printf("\nVocê selecionou a opção 4\n");
                break;
            case 0:
                sair();
                break;
            default:
                printf("digite uma opção válida!\n");
        }
    } while (seletor);

    //Desalocando memória dos vetores ContA e ContB
    free(ContA);
    free(ContB);
    //Fechando os arquivos
    fclose(dicionario);
    fclose(arquivoA);
    fclose(bowA);

    return 0;
}
