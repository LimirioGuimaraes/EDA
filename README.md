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
void arqD(FILE *arq_d, int *ContA, int *ContB);
void arqTRA(FILE *arq_tra, FILE *arq_d, FILE *arqBOWA, int *ContA);


//Função principal.
int main(){
    FILE *arq_d, *arq_tra, *arq_trb, *arqBOWA, *arqBOWB;
    char menu;
    int *ContA, *ContB;


    do{
        MENU();

        printf("\n\nOpcao: ");
        scanf(" %c", &menu);
        setbuf(stdin, NULL);

        system("cls || clear");

        switch (menu){
            case '1':
                arqD(arq_d, ContA, ContB);
                break;
            case '2':
                arqTRA(arq_tra, arq_d, arqBOWA, ContA);
                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                    fclose(arq_d);
                    fclose(arq_tra);
                    fclose(arq_trb);
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


void arqD(FILE *arq_d, int *ContA, int *ContB){
    char nome_d[20], palavra[100];
    int tam;

    printf("\n Insira o nome do arquivo de dicionario: ");
    scanf("%s", nome_d);
    setbuf(stdin, NULL);

    arq_d= fopen(nome_d, "r");

    printf("\n\n");

    if(arq_d != NULL){
        while(fgets(palavra, 100, arq_d) != NULL){
            printf("%s", palavra);
            tam++;
        }
        printf("\n\n");
    }

    ContA = (int *) malloc(tam * sizeof(int));
    ContB = (int *) malloc(tam * sizeof(int));

    if(arq_d == NULL)
        printf("\nArquivo nao encontrado.\n\n");

    system("pause");

    system("cls || clear");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void arqTRA(FILE *arq_tra, FILE *arq_d, FILE *arqBOWA, int *ContA){
    char nome_tra[20], palavra[100], palavra2[100], texto[100];
    int freq;

    printf("\n Insira o nome do arquivo de texto de referência A: ");
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

    while(fgets(palavra2, 100, arq_d) != NULL){
        while(fgets(palavra, 100, arq_tra) != NULL){
            if(strcmp(palavra2,palavra) == 0)
                freq++;
        }
        arqBOWA= fopen("bowA.txt", "w");
            texto=freq;
            fputs(texto, arqBOWA);
            ContA=freq;
            freq=0;
    }

    system("pause");

    system("cls || clear");

}
