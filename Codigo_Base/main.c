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
int sair() /*O(1)*/ {
    printf("Saindo do programa...\n"); /*O(1)*/
}

int main() /*O(N^2)*/ {
    //Declaração de variáveis
    int seletor = 1, *ContA, *ContB, n_palavras = 0, i = 0, soma; /*O(1)*/
    double DistEuclid; /*O(1)*/
    FILE *dicionario, *arquivoA, *arquivoB, *bowA, *bowB; /*O(1)*/
    char *nomeArquivo, palavrasDicionario[50]; /*O(1)*/

    do {
        printf("\n\tMenu de opcoes:\n\n"); /*O(1)*/
        printf("1. Selecionar arquivo dicionario\n"); /*O(1)*/
        printf("2. Selecionar texto de referencia A\n"); /*O(1)*/
        printf("3. Selecionar texto de referencia B\n"); /*O(1)*/
        printf("4. Imprimir BOWs dos textos referencia\n"); /*O(1)*/
        printf("5. Similaridade entre os dois rextos de referencia (Distancia Euclidiana)\n"); /*O(1)*/
        printf("0. Sair\n\n"); /*O(1)*/
        printf("Digite a opcao desejada (SOMENTE NUMEROS): "); /*O(1)*/

        scanf("%d", &seletor); /*O(1)*/
        system ("cls || clear"); /*O(1)*/

        switch (seletor){
            case 1:
                //Lógica para leitura do dicionário
                dicionario = LeituraArquivo(dicionario); /*O(1)*/
                //Contagem de palavras dentro do dicionario
                n_palavras = ContarPalavras(dicionario); /*O(N)*/
                //Alocação de memória para os vetores contA e contB
                ContA = (int*) malloc(n_palavras*sizeof(int)); /*O(1)*/
                ContB = (int*) malloc(n_palavras*sizeof(int)); /*O(1)*/
                break;
            case 2:
                //Lógica para a leitura do texto de referência A
                arquivoA = LeituraArquivo(arquivoA); /*O(1)*/
                //Criando o arquivo bowA
                nomeArquivo = "bowA.txt"; /*O(1)*/
                bowA = CriarBOW(bowA, arquivoA, dicionario, nomeArquivo, ContA)/*O(N^2)*/;
                break;
            case 3:
                //Lógica para a leitura do texto de referência B
                arquivoB = LeituraArquivo(arquivoB); /*O(1)*/
                //Criando o arquivo bowA
                nomeArquivo = "bowB.txt"; /*O(1)*/
                bowB = CriarBOW(bowB, arquivoB, dicionario, nomeArquivo, ContB); /*O(N^2)*/
                break;
            case 4:
                //Parte responsável pela tabela de BOWs
                printf("\nPalavras      Texto A (#)     Texto B (#)\n"); /*O(1)*/
                ImprimeBOW(ContA, ContB, dicionario); /*O(N)*/
                break;
            case 5:
                //Lógica para calcular distância euclidiana entre os vetores contA e contB
                soma = 0; /*O(1)*/
                while (i != n_palavras) /*O(N)*/ {
                    soma = soma + pow((ContA[i]-ContB[i]),2); /*O(1)*/
                    i++; /*O(1)*/
                }
                DistEuclid = sqrt(soma); /*O(1)*/
                //Impressão do resultado
                printf("\nDistancia Euclidiana (Quanto maior o numero, menos similares sao os textos):"); /*O(1)*/
                printf(" %lf\n", DistEuclid); /*O(1)*/
                break;
            case 0:
                //Saída do programa
                sair(); /*O(1)*/
                break;
            default:
                //Caso seja digitado um número não válido
                printf("Digite uma opcao valida!\n"); /*O(1)*/
        }
    } while (seletor) /*O(N)*/ ;

    //Desalocando memória dos vetores ContA e ContB
    free(ContA); /*O(1)*/
    free(ContB); /*O(1)*/
    //Fechando os arquivos
    fclose(dicionario); /*O(1)*/
    fclose(arquivoA); /*O(1)*/
    fclose(arquivoB); /*O(1)*/
    fclose(bowA); /*O(1)*/
    fclose(bowB); /*O(1)*/

    return 0; /*O(1)*/
}
