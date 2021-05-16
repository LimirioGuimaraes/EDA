#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CalcFatBal.c"

void imprime_menu ();
void ImprimeOrdem (No *no);

int main() {
    struct No *c = NULL;
    char nomeArquivo[20];
    int menu;

      do
           {
               imprime_menu ();
               scanf ("%d", &menu);
               system("cls || clear ");
               getchar();

               switch (menu)
                {
                case 1:
                    printf("Digite o nome do arquivo desejado: ");
                    scanf("%s", nomeArquivo);
                    c = GeraABP(c, nomeArquivo);
                    break;
                case 2:
                    c = CalcFatBal(c);
                    break;
                case 3:
                    if(c == NULL){
                        printf("Árvore nula!!\n");
                        break;
                    } else {
                        ImprimeOrdem(c);
                    }
                case 4:
                    break;
                default:
                    printf ("Numero incorreto!!\7\n");
                }
            }
        while (menu != 4);
        free (c);
        return 0;
}

void imprime_menu ()
{
        printf("1. Gerar ABP\n");
        printf("2. Calcula Fator de Balanceamento\n");
        printf("3. Imprime ABP\n");
        printf("4. Sair\n");
        printf("Opção: ");

}

void ImprimeOrdem (No *no){
    if(no != NULL){
        ImprimeOrdem(no -> pEsq);
        printf("{Chave: %d, Fator de Balanceamento: %d}\n", no -> chave,  no -> FatBal);
        ImprimeOrdem(no -> pDir);
    }
}