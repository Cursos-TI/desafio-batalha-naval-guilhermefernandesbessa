#include <stdio.h>

void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Void para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Void para ver se a posição é valida
int posicaoLivre(int tabuleiro[10][10], int c, int l, int posicao) {
    for (int i = 0; i < 3; i++) {
        int novoC = c, novoL = l; 
// Fiz o novoC e um novoL pois se nao os fizesse, ficaria '3 3 0 3' ao inves de '3 3 3'  

// Horizontal
    if (posicao == 0) {
            novoL += i;
        }
// Vertical
    else if (posicao == 1) {
            novoC += i;
        }
// Diagonal Cima Direita
    else if (posicao == 2) {
        novoC += i;
            novoL += i;
        }
// Diagonal Baixo Direita
    else if (posicao == 3) {
        novoC += i;
            novoL -= i;
        }

        if (novoL < 0 || novoL >= 10 || novoC < 0 || novoC >= 10 || tabuleiro[novoL][novoC] == 3) {
            return 0; // posição inválida ou já ocupada
        }
    }
    return 1; // posição válida
}

// Void para posicionar os navios
void posicionarNavio(int tabuleiro[10][10], int c, int l, int posicao) {
    for (int i = 0; i < 3; i++) {
        int novoC = c, novoL = l;
// Fiz o novoC e um novoL pois se nao os fizesse, ficaria '3 3 0 3' ao inves de '3 3 3' 

// Horizontal
    if (posicao == 0) {
            novoL += i;
        }
// Vertical
    else if (posicao == 1) {
            novoC += i;
        }
// Diagonal Cima Direita
    else if (posicao == 2) {
        novoC += i;
            novoL += i;
        }
// Diagonal Cima Direita
    else if (posicao == 3) {
        novoC += i;
            novoL -= i;
        }

        tabuleiro[novoC][novoL] = 3; // Marca a posição do navio com 3
    }
}

int main() {
    int tabuleiro[10][10];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
//<><><><   C = COLUNA;  L = LACUNA; ><><><><>   
//~~~~~ Definir manualmente as coordenadas e direções dos navios
    
// Primeiro navio (Horizontal)
    int c1 = 9, l1 = 1, posicao1 = 0; // posicao1 = 0 (Horizontal)
        if (posicaoLivre(tabuleiro, c1, l1, posicao1)) {
            posicionarNavio(tabuleiro, c1, l1, posicao1);
        }

// Segundo navio (Vertical)
    int c2 = 4, l2 = 1, posicao2 = 1; // posicao2 = 1 (Vertical)
        if (posicaoLivre(tabuleiro, c2, l2, posicao2)) {
            posicionarNavio(tabuleiro, c2, l2, posicao2);
        }

// Terceiro navio (Diagonal Cima Direita)
    int c3 = 4, l3 = 4, posicao3 = 2; // Posicao3 = 2 (Diagonal Cima Direita)
        if (posicaoLivre(tabuleiro, c3, l3, posicao3)) {
            posicionarNavio(tabuleiro, c3, l3, posicao3);
        }

// Quarto navio (Diagonal Baixo Direita)
    int c4 = 1, l4 = 8, posicao4 = 3; // posicao4 = 3 (Diagonal Baixo Direita)
        if (posicaoLivre(tabuleiro, c4, l4, posicao4)) {
            posicionarNavio(tabuleiro, c4, l4, posicao4);
        }

// Exibir o tabuleiro
    if (posicaoLivre(tabuleiro, c1, l1, posicao4) && 
            posicaoLivre(tabuleiro, c2, l2, posicao4) &&
                posicaoLivre(tabuleiro, c3, l3, posicao4) &&
            posicaoLivre(tabuleiro, c4, l4, posicao4)? 0 : 1)
    {// Se tudo for verdadeiro entao exibira o tabuleiro
        exibirTabuleiro(tabuleiro);
    } else {
        printf("Alguma posição esta errada!!!");
    }

    return 0;
}