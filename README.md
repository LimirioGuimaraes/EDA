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
void arqD(FILE *arq_d, char nome_d[], int *tam);


//Função principal.
int main(){
    FILE *arq_d, *arq_tra, *arq_trb;
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
                arqD(arq_d, nome_d, &tam);
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
    }while(menu != '6');

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


void arqD(FILE *arq_d, char nome_d[20], int *tam){
    char palavra[100];

    printf("\n Insira o nome do arquivo de dicionario: ");
    scanf("%s", nome_d);
    setbuf(stdin, NULL);

    arq_d= fopen(nome_d, "r");

    printf("\n\n");

    if(arq_d != NULL){
        while(fgets(palavra, 100, arq_d) != NULL){
            printf("%s", palavra);
            (*tam)++;
        }
        printf("\n\n");
    }

    if(arq_d == NULL)
        printf("\nArquivo nao encontrado.\n\n");

    system("pause");

    system("cls || clear");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void arqTRA(FILE *arq_tra, char nome_tra[20], int *ContA){
    char palavra[100];

    printf("\n Insira o nome do arquivo de dicionario: ");
    scanf("%s", nome_tra);
    setbuf(stdin, NULL);

    arq_tra= fopen(nome_tra, "r");

    printf("\n\n");

    if(arq_tra != NULL){
        while(fgets(palavra, 100, arq_tra) != NULL){
            printf("%s", palavra);
        }
        printf("\n\n");
    }

    if(arq_tra == NULL)
        printf("\nArquivo nao encontrado.\n\n");

    fgets(palavra, 100, arq_d)

    system("pause");

    system("cls || clear");

}
