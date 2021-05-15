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
    // Varivável que irá guardar o valor a inserir na árvore
    int valor, adicionou = 0;
    // Ponteiro para abertura e leitura do arquivo
    FILE *Csv;
    // Abrir o arquivo em modo de leitura
    Csv = fopen(nomeArquivo, "r");
    // Se a abertura do aquivo falhar...
    if(Csv == NULL){
        return NULL;
    }
    // Enquanto o ponteiro de arquivo não chegar ao fim do arquivo...
    while(!feof(Csv)){
        // Escanear o valor no seguinte formato: "%d, "
        fscanf(Csv, "%d, ", &valor);
        // Alocar espaço para no novo nó e declarar o ponteiro auxiliar
        struct No *NovoNo = malloc(sizeof(No)), *aux;
        // Atribuir valor o novo nó e direcionar os seus ponteiros
        NovoNo -> chave = valor;
        NovoNo -> pEsq = NULL;
        NovoNo -> pDir = NULL;
        // Se a cabeça é nula (Árvore vazia) ....
        if (cabeca ==  NULL){
            // Setar a cabeça da árvore para o novo nó
            cabeca = NovoNo;
        // Caso contrário, checar se o valor deve ser inserido à esquerda ou à direita
        } else {
            // O ponteiro auxiliar deve apontar para a cabeça do nó para não modificarmos a cabeça 
            aux = cabeca;
            // Enquanto não adicionar nenuhm elemento, procurar a posição na qual devemos adicionar
            while (adicionou == 0){
                // Caso o valor seja menor do que a chave para qual aux está apontando,
                //                                                          adicionar à esqueda:
                if(valor < aux -> chave){
                    // Checar se a posição na qual devemos adicionar é nula
                    if(aux -> pEsq == NULL){
                        aux -> pEsq = NovoNo;
                        adicionou = 1;
                    } else {
                        aux = aux -> pEsq;
                    }
                // Caso contrário, adicionar à direita:
                } else if(valor > aux -> chave){
                    if(aux -> pDir == NULL){
                        aux -> pDir = NovoNo;
                        adicionou = 1;
                    } else {
                        aux = aux -> pDir;
                    }
                } else if(valor == aux -> chave){
                    adicionou = 1;
                }
            }
            adicionou = 0;
        }  
    }
    // Fechar o arquivo e retornar o nó cabeça
    fclose(Csv);
    return cabeca;
}
