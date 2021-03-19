# Comparar textos

## algoritmo
###### Síntese
Objetivo: Comparar textos de arquivo<br/>
Entrada: Dicionário e 2 textos de referência<br/>
Saída: Similaridade entre os textos

## Descrição Assintótica do projeto

###### Função Sair

**f(n) = O(1) + O(1)**
**f(n) = O(1)**

###### Função Leitura Arquivo

**f(n) = 9x(O(1))**
**f(n) = O(1)**

###### Função Contar Palavras

**f(n) = 5x(O(1)) + O(N)**
**f(n) = O(N)**

###### Função Criar BOW

**f(n) = 17x(O(1)) + O(N) + O(N^2)**
**f(n) = O(N^2)**

###### Função Imprime BOW

**f(n) = 6x(O(1)) + O(N)**
**f(n) = O(N)**


###### Função main

**f(n) = 38x(O(1)) + 4x(O(N)) + 2x(O(N^2))**
**f(n) = O(N^2)**

## Complexidade geral do código

**f(n) = O(N^2)**
