#include <stdio.h>
#include <stdlib.h>
#include "GeraABP.c"



No *CalcFatBal(No *cabeca){
    // Se o nó cabeça for nulo, retornar Fator de balanceamento 0
    if(cabeca == NULL){
        cabeca -> FatBal = 0;
        return cabeca;
    }
    No *aux = cabeca;

    aux -> FatBal = EncontraFatBal(aux);

    return cabeca;
}