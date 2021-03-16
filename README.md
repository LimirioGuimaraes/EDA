/*              algoritmo
    Síntese
    Objetivo: Comparar textos de arquivo;
    Entrada:
    Saída:                 */


//Declaração de bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MENU();
void arqDIC(FILE *arq, char nome_d[], int *tam);
//Função principal.
int main(){
    FILE *arq;
    char menu, nome_d[20], nome_tra[20], nome_trb[20];
    int tam, *ContA, *ContB;


    do{
        MENU();

        printf("\n\nOpcao: ");
        scanf(" %c", &menu);
        setbuf(stdin, NULL);

        system("cls || clear");

        switch (menu){
            case '1':
                arqDIC(arq, nome_d, &tam);
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':

                break;
            default:
                break;
        }
    }while(menu != 6);

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MENU(){
    printf("\t\tComparacao de textos de arquivo");
    printf("\n\n1 - Ler arquivo de dicionario");
    printf("\n2 - Ler o texto de referencia A");
    printf("\n3 - Ler o texto de referencia B");
    printf("\n4 - BOWs de TRA e TRB");
    printf("\n5 - Similaridades entre os textos e a Distancia Euclidiana");
    printf("\n6 - Sair");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void arqDIC(FILE *arq, char nome_d[20], int *tam){
    char palavra[100];

    printf("\n Insira o nome do arquivo de dicionario: ");
    scanf("%s", nome_d);
    setbuf(stdin, NULL);

    arq= fopen(nome_d, "r");

    printf("\n\n");

    if(arq != NULL){
        while(fgets(palavra, 100, arq) != NULL){
            printf("%s", palavra);
            (*tam)++;
        }
        printf("\n\n");
    }

    if(arq == NULL)
        printf("\nArquivo nao encontrado.\n\n");

    system("pause");

    system("cls || clear");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arqTRA(){

}
