// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO - NÍVEL NOVATO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema para cadastro dos territórios do jogo
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define QTD_TERRITORIOS 5
#define TAM_MAX_NOME 30
#define TAM_MAX_COR 10

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    char nome[TAM_MAX_NOME];
    char cor[TAM_MAX_COR];
    int tropas;
};

// --- Funções ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar os territórios
void cadastrarTerritorios(struct Territorio territorios[], int tamanho) {
    printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n\n");

    // Cadatra os territórios de acordo com a quantidade máxima definida em QTD_TERRITORIOS
    for (int i = 0; i < tamanho; i++) {
        printf("--- Cadastrando Territorio %i ---", i + 1);

        // Ler os nomes, cores dos exércitos e números de tropas dos territórios
        printf("\nDigite o nome do território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);

        printf("Cor do exército (Ex: Azul, Verde): ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        printf("\n");

        limparBufferEntrada();
    }
}

// Função para exibir os territórios cadastrados
void exibirTerritorios(struct Territorio territorios[], int tamanho) {
    printf("\n\n==================================================\n        MAPA DO MUNDO - ESTADO ATUAL        \n==================================================\n");

    // Percorre a lista de territórios e exibe seus nomes, cores dos exércitos e números de tropas
    for (int i = 0; i < tamanho; i++) {
        printf("\nTERRITORIO %i", i + 1);
        printf("\n\t- Nome: %s", territorios[i].nome);
        printf("\t- Cor do exército: %s", territorios[i].cor);
        printf("\t- Tropas: %i", territorios[i].tropas);
    }
}

int main() {
    // Definição de variáveis    
    struct Territorio territorios[QTD_TERRITORIOS];

    // Chama função para cadastrar os territórios
    cadastrarTerritorios(territorios, QTD_TERRITORIOS);

    printf("\nCadastrado inicial realizado com sucesso!");

    // Chama função para exibir os territórios
    exibirTerritorios(territorios, QTD_TERRITORIOS);

    printf("\n");

    return 0;
}

// --- Implementação das Funções ---

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.

// cadastrarTerritorios();
// Função para cadastrar os territórios

// exibirTerritorios();
// Função para exibir os territórios cadastrados