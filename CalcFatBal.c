#include <stdio.h>
#include <stdlib.h>
#include "GeraABP.c"

int CalcAltura(No *no){
    int tamDir = 0, tamEsq = 0;
    if(no != NULL) {
        if (no -> pEsq != NULL){
            tamEsq = CalcAltura(no -> pEsq) + 1;
        }
        if (no -> pDir != NULL){
            tamDir = CalcAltura(no -> pDir) + 1;
        }
    }

    if (tamEsq >= tamDir){
        return tamEsq;
    } else {
        return tamDir;
    }
}

int FatBal (No *no){
    int Esq = 0, Dir = 0;

    if(no -> pDir != NULL){
        Dir = CalcAltura (no -> pDir);
    }

    if (no -> pEsq != NULL){
        Esq = CalcAltura (no -> pEsq);
    }

    return abs(Esq - Dir);
}

No *CalcFatBal(No *cabeca){

    // Se o nó cabeça for nulo, retornar Fator de balanceamento 0
    if(cabeca == NULL){
        cabeca -> FatBal = 0;
        return cabeca;
    }
    cabeca -> FatBal = FatBal(cabeca);
    return cabeca;
}
