#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se é possível posicionar o navio sem ultrapassar os limites ou sobrepor outro navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (horizontal ? 0 : i);
        int y = coluna + (horizontal ? i : 0);

        if (x >= TAM_TABULEIRO || y >= TAM_TABULEIRO || tabuleiro[x][y] != VALOR_AGUA) {
            return 0; // Não pode posicionar
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (horizontal ? 0 : i);
        int y = coluna + (horizontal ? i : 0);
        tabuleiro[x][y] = VALOR_NAVIO;
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);





    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
