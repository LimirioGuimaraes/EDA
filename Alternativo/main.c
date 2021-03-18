#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibliotecas/LeituraArquivo.h"
#include "Bibliotecas/CriarBOW.h"
#include "Bibliotecas/ContarPalavras.h"
#include "Bibliotecas/ImprimeBOW.h"

int sair(){
    printf("Saindo do programa...\n");
}

int main(){

    int seletor = 1, *ContA, *ContB, n_palavras = 0, i;
    FILE *dicionario, *arquivoA, *arquivoB, *bowA, *bowB;
    char *nomeArquivo, palavrasDicionario[50];

    dicionario = NULL;

    do {
        printf("\n\tMenu de opções:\n\n");
        printf("1. Selecionar arquivo dicionário\n");
        printf("2. Selecionar texto de referência A\n");
        printf("3. Selecionar texto de referência B\n");
        printf("4. Imprimir BOWs dos textos referência\n");
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

                //Criando o arquivo bowA
                nomeArquivo = "bowA.txt";
                bowA = CriarBOW(bowA, arquivoA, dicionario, nomeArquivo, ContA);
                /*Somente tirar o comentário para conferir a passagem do ponteiro
                (Vide CriarArquivo.h)
                printf("\n%p\n",bowA);*/
                break;
            case 3:
                arquivoB = LeituraArquivo(arquivoB);
                /*Somente tirar o comentário para conferir os endereços de memória utilizados
                printf("\n%p\n", arquivoA);*/

                //Criando o arquivo bowA
                nomeArquivo = "bowB.txt";
                bowB = CriarBOW(bowB, arquivoB, dicionario, nomeArquivo, ContB);
                /*Somente tirar o comentário para conferir a passagem do ponteiro
                (Vide CriarArquivo.h)
                printf("\n%p\n",bowA);*/
                break;
            case 4:
                printf("\nPalavras      Texto A (#)     Texto B (#)\n");
                ImprimeBOW(ContA, ContB, dicionario);
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
