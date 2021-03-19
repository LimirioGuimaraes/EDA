/*
Autores:

Breno Alexandre Soares Garcia - 20/0035703
Janaína Aparecida Queiroz Rabelo - 20/0038915
Hoton Geraldo do Carmo Junior - 20/0038389
Limirio Correia Guimaraes - 20/0040201
Matheus Pimentel Leal - 15/0141629


              algoritmo
    Síntese:
    Objetivo: Comparar textos de arquivo;
    Entrada:
    Saída:
*/

//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Bibliotecas/LeituraArquivo.h"
#include "Bibliotecas/CriarBOW.h"
#include "Bibliotecas/ContarPalavras.h"
#include "Bibliotecas/ImprimeBOW.h"

//Função de saída do programa
int sair(){
    printf("Saindo do programa...\n");
}

int main(){
    //Declaração de variáveis
    int seletor = 1, *ContA, *ContB, n_palavras = 0, i = 0, soma;
    double DistEuclid;
    FILE *dicionario, *arquivoA, *arquivoB, *bowA, *bowB;
    char *nomeArquivo, palavrasDicionario[50];

    do {
        printf("\n\tMenu de opcoes:\n\n");
        printf("1. Selecionar arquivo dicionario\n");
        printf("2. Selecionar texto de referencia A\n");
        printf("3. Selecionar texto de referencia B\n");
        printf("4. Imprimir BOWs dos textos referencia\n");
        printf("5. Similaridade entre os dois rextos de referencia (Distancia Euclidiana)\n");
        printf("0. Sair\n\n");
        printf("Digite a opcao desejada (SOMENTE NUMEROS): ");

        scanf("%d", &seletor);
        system ("cls || clear");

        switch (seletor){
            case 1:
                //Lógica para leitura do dicionário
                dicionario = LeituraArquivo(dicionario);
                //Contagem de palavras dentro do dicionario
                n_palavras = ContarPalavras(dicionario);
                //Alocação de memória para os vetores contA e contB
                ContA = (int*) malloc(n_palavras*sizeof(int));
                ContB = (int*) malloc(n_palavras*sizeof(int));
                break;
            case 2:
                //Lógica para a leitura do texto de referência A
                arquivoA = LeituraArquivo(arquivoA);
                //Criando o arquivo bowA
                nomeArquivo = "bowA.txt";
                bowA = CriarBOW(bowA, arquivoA, dicionario, nomeArquivo, ContA);
                break;
            case 3:
                //Lógica para a leitura do texto de referência B
                arquivoB = LeituraArquivo(arquivoB);
                //Criando o arquivo bowA
                nomeArquivo = "bowB.txt";
                bowB = CriarBOW(bowB, arquivoB, dicionario, nomeArquivo, ContB);
                break;
            case 4:
                //Parte responsável pela tabela de BOWs
                printf("\nPalavras      Texto A (#)     Texto B (#)\n");
                ImprimeBOW(ContA, ContB, dicionario);
                break;
            case 5:
                //Lógica para calcular distância euclidiana entre os vetores contA e contB
                soma = 0;
                while (i != n_palavras){
                    soma = soma + pow((ContA[i]-ContB[i]),2);
                    i++;
                }
                DistEuclid = sqrt(soma);
                //Impressão do resultado
                printf("\nDistancia Euclidiana (Quanto maior o numero, menos similares sao os textos):");
                printf(" %lf\n", DistEuclid);
                break;
            case 0:
                //Saída do programa
                sair();
                break;
            default:
                //Caso seja digitado um número não válido
                printf("Digite uma opcao valida!\n");
        }
    } while (seletor);

    //Desalocando memória dos vetores ContA e ContB
    free(ContA);
    free(ContB);
    //Fechando os arquivos
    fclose(dicionario);
    fclose(arquivoA);
    fclose(arquivoB);
    fclose(bowA);
    fclose(bowB);

    return 0;
}
