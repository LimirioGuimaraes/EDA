# Comparar textos

###### algoritmo
        __ Síntese __
Objetivo: Comparar textos de arquivo;
Entrada: Dicionário e 2 textos de referência
Saída: Similaridade entre os textos

## Descrição Assintórica do projeto

###### Função Sair

__ f(n) = O(1) + O(1) __
__ f(n) = O(1) __

###### Função Leitura Arquivo

__ f(n) = 9x(O(1)) __
__ f(n) = O(1) __

###### Função Contar Palavras

__ f(n) = 5x(O(1)) + O(N) __
__ f(n) = O(N) __

###### Função Criar BOW

__ f(n) = 17x(O(1)) + O(N) + O(N^2) __
__ f(n) = O(N^2) __

###### Função Imprime BOW

__ f(n) = 6x(O(1)) + O(N) __
__ f(n) = O(N) __


###### Função main

__ f(n) = 38x(O(1)) + 4x(O(N)) + 2x(O(N^2)) __
__ f(n) = O(N^2) __

## Complexidade geral do código

__ f(n) = O(N^2) __
