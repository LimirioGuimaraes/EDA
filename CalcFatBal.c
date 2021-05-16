#include <stdio.h>
#include <stdlib.h>
#include "GeraABP.c"

int CalcAltura(No *no){
    int tamDir = 0, tamEsq = 0;

    if (no == NULL){
        return 0;
    } else {
        if (no -> pEsq != NULL){
            tamEsq = CalcAltura(no -> pEsq) + 1;
        }
        if (no -> pDir != NULL){
            tamDir = CalcAltura(no -> pDir) + 1;
        }
    }

    if (tamEsq <= tamDir){
        return tamEsq;
    } else {
        return tamDir;
    }
}

No *CalcFatBal(No *cabeca){
    
    // Se o nó cabeça for nulo, retornar Fator de balanceamento 0
    if(cabeca == NULL){
        cabeca -> FatBal = 0;
        return cabeca;
    }

    return cabeca;
}