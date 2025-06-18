#include <stdio.h>
#include <stdlib.h> // Para uso da função abs

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

//Constantes
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5
#define TAM_HABILIDADE 5

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

// Função para posicionar o navio no tabuleiro na horizontal ou vertical
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + (horizontal ? 0 : i);
        int y = coluna + (horizontal ? i : 0);
        tabuleiro[x][y] = VALOR_NAVIO;
    }
}

// Função para verificar se pode posicionar um navio na diagonal
int podePosicionarDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int principal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + i;
        int y = principal ? (coluna + i) : (coluna - i);

        if (x >= TAM_TABULEIRO || y < 0 || y >= TAM_TABULEIRO || tabuleiro[x][y] != VALOR_AGUA) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int principal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int x = linha + i;
        int y = principal ? (coluna + i) : (coluna - i);
        tabuleiro[x][y] = VALOR_NAVIO;
    }
}

// Gera matriz em formato de cone com expansão central para base
void gerarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Marca 1 nos pontos dentro da abertura do cone
            habilidade[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Gera matriz em formato de cruz (linha e coluna centrais marcadas)
void gerarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Gera matriz em formato de octaedro (losango centrado)
void gerarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Soma das distâncias absolutas ao centro menor ou igual ao raio
            habilidade[i][j] = (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Aplica matriz de habilidade sobre o tabuleiro a partir de um ponto central
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemLinha - offset + i;
            int y = origemColuna - offset + j;
            // Marca a habilidade no tabuleiro apenas se dentro dos limites e em água
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && habilidade[i][j] == 1 && tabuleiro[x][y] == VALOR_AGUA) {
                tabuleiro[x][y] = VALOR_HABILIDADE;
            }
        }
    }
}


// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            char c;
            if (tabuleiro[i][j] == VALOR_AGUA) c = '0';
            else if (tabuleiro[i][j] == VALOR_NAVIO) c = '3';
            else if (tabuleiro[i][j] == VALOR_HABILIDADE) c = '5';
            else c = '?';
            printf("%c ", c);
        }
        printf("\n");
    }
}


int main() {

    //Declarando o tabuleiro e as Matrizes de habilidades
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaH = 1, colunaH = 2; // Horizontal
    int linhaV = 4, colunaV = 5; // Vertical
    int linhaD1 = 0, colunaD1 = 0; // Diagonal principal
    int linhaD2 = 0, colunaD2 = 9; // Diagonal secundária

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Valida e posiciona o navio horizontal
    if (podePosicionar(tabuleiro, linhaH, colunaH, 1)) {
        posicionarNavio(tabuleiro, linhaH, colunaH, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Valida e posiciona o navio vertical
    if (podePosicionar(tabuleiro, linhaV, colunaV, 0)) {
        posicionarNavio(tabuleiro, linhaV, colunaV, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Posiciona navios diagonais
    if (podePosicionarDiagonal(tabuleiro, linhaD1, colunaD1, 1)) {
        posicionarNavioDiagonal(tabuleiro, linhaD1, colunaD1, 1);
    } else {
        printf("Erro: Não foi possível posicionar navio diagonal principal.\n");
    }

    if (podePosicionarDiagonal(tabuleiro, linhaD2, colunaD2, 0)) {
        posicionarNavioDiagonal(tabuleiro, linhaD2, colunaD2, 0);
    } else {
        printf("Erro: Não foi possível posicionar navio diagonal secundária.\n");
    }

    // Gera as matrizes de habilidades
    gerarHabilidadeCone(cone);
    gerarHabilidadeCruz(cruz);
    gerarHabilidadeOctaedro(octaedro);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);





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
