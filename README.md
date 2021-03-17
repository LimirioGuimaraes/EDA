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
void LeituraDicionario(FILE *Dicionario, int *ContA, int *ContB);
void arqTRA(FILE *arq_tra, FILE *Dicionario, FILE *arqBOWA, int *ContA);


//Função principal.
int main(){
    FILE *Dicionario, *arq_tra, *arq_trb, *arqBOWA, *arqBOWB;
    char menu;
    int N_PalavrasD, N_PalavrasTRA, N_PalavrasTRB, *ContA, *ContB;


    do{
        MENU();

        printf("\n\nOpcao: ");
        scanf(" %c", &menu);
        setbuf(stdin, NULL);

        system("cls || clear");

        switch (menu){
            case '1':
                LeituraDicionario(Dicionario, ContA, ContB);
                break;
            case '2':
                arqTRA(arq_tra, Dicionario, arqBOWA, ContA);
                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                    fclose(Dicionario);
                    fclose(arq_tra);
                    fclose(arq_trb);
                break;
            default:
                break;
        }
    }while(menu != '6');

    return 0;
}


/*-------------------------------------------------------------------void's e funções--------------------------------------------------*/
//void para chamar o menu
void MENU(){
    printf("\t\tComparacao de textos de arquivo");
    printf("\n\n1 - Ler arquivo de dicionario");
    printf("\n2 - Ler o texto de referencia A");
    printf("\n3 - Ler o texto de referencia B");
    printf("\n4 - BOWs de TRA e TRB");
    printf("\n5 - Similaridades entre os textos e a Distancia Euclidiana");
    printf("\n6 - Sair");
}




//Função responsável por acessar o dicionário informado pelo usuário
void LeituraDicionario(FILE *Dicionario, int *ContA, int *ContB){
    char NomeDicionario[20], palavra[100];
    int N_Palavras;

    printf("\n Insira o nome do dicionario: ");
    scanf("%s", NomeDicionario);
    setbuf(stdin, NULL);

    Dicionario= fopen(NomeDicionario, "r");

    printf("\n\n");

    if(Dicionario != NULL){
        while(fgets(palavra, 100, Dicionario) != NULL){
            printf("%s", palavra);
            N_Palavras++;
        }
        printf("\n\n");
        printf("\n\nAgora o arquivo '%s' e um dicionario!\n\n", NomeDicionario);
    }else{
        printf("Erro na abertura do arquivo nomeado!\n\n");
    }

    ContA = (int *) malloc(N_Palavras * sizeof(int));
    ContB = (int *) malloc(N_Palavras * sizeof(int));

    system("pause");

    system("cls || clear");
}




//função responsável por abrir o TRA e ccomparar com o dicionário
void arqTRA(FILE *arq_tra, FILE *Dicionario, FILE *arqBOWA, int *ContA){
    char nome_tra[20], palavra1[200], palavra2[200], texto;
    int freq=0, tamanho=0;

    printf("\n Insira o nome do arquivo de texto de referencia A: ");
    scanf("%s", nome_tra);
    setbuf(stdin, NULL);

    arq_tra= fopen(nome_tra, "r");

    printf("\n\n");

    if(arq_tra != NULL){
        while(fgets(palavra1, 200, arq_tra) != NULL){
            printf("%s", palavra1);
        }
        printf("\n\n");

        arqBOWA= fopen("bowA.txt", "w");

    }else{
        printf("\nArquivo nao encontrado.\n\n");
    }

    while(fgets(palavra1, 200, Dicionario) != NULL){
        do{
            if (fgets(palavra2, 200, arq_tra) != NULL){
                if(strcmp(palavra1,palavra2) == 0)
                    freq++;
            }
        }while(palavra2 != NULL);
        texto=freq+'0';
        fprintf(arqBOWA, "%c", texto);
        ContA[tamanho]=freq;
        freq=0;
        tamanho++;
    }

    system("pause");

    system("cls || clear");

}
