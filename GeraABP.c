#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fator de balanceamento = |Altura do nó da direita - Altura do nó da esquerda|

// Estrutura de um nó da árvore binária
typedef struct No{
    // Valor armazenado no nó
    int chave;
    // Ponteiros do nó (Para a esquerda e direita, menor e maior respectivamente)
    struct No *pEsq, *pDir;
    // Fator de balanceamento do nó
    int FatBal;
}No;

No *GeraABP(No *cabeca, char nomeArquivo[20]){
    int valor;
    // Alocar espaço para no novo nó
    struct No *NovoNo = malloc(sizeof(No)), *aux;
    // Ponteiro para abertura e leitura do arquivo
    FILE *Csv;
    // Abrir o arquivo em modo de leitura
    Csv = fopen(nomeArquivo, "r");
    while (Csv != '\0'){
        fscanf(Csv, "%d", &valor);
    }
    // Checar se a cabeça é nula (Árvore vazia)
    if (cabeca ==  NULL){
        // Atribuir valor ao novo nó e setar ponteiros para NULL
        NovoNo -> chave = valor;
        NovoNo -> pEsq = NULL;
        NovoNo -> pDir = NULL;
        cabeca = NovoNo;
    } else {
        aux = cabeca;
        NovoNo -> chave = valor;
        NovoNo -> pEsq = NULL;
        NovoNo -> pDir = NULL;
        if(valor <= aux -> chave){
            aux -> pEsq = NovoNo;
        } else {
            printf("Deu bosta\n");
        }
    }
    fclose(Csv);
    return cabeca;
}
