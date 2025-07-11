#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercício 1: Cadastro de Pessoas
 *
 * Objetivo:
 * Implementar um sistema simples de cadastro de pessoas utilizando alocação dinâmica de memória.
 *
 * Cada pessoa possui:
 *  - Nome (char* nome)
 *  - Idade (int idade)
 *  - Endereço (char* endereco)
 *
 * Funcionalidades:
 * 1. Permitir ao usuário cadastrar várias pessoas.
 * 2. Para cada pessoa:
 *    - Alocar dinamicamente memória para nome e endereço.
 *    - Ler as informações do usuário.
 * 3. Armazenar todos os dados em um arquivo binário chamado "cadastros.dat".
 * 4. Após o cadastro, abrir o arquivo e exibir todas as informações cadastradas.
 *
 * Dicas:
 * - Utilize malloc para alocação dinâmica.
 * - Utilize fwrite e fread para manipulação do arquivo binário.
 * - Lembre-se de liberar toda a memória alocada ao final do programa.
 *
 * Desafio: 
 * Implementar um menu com 'do while' para que o usuário escolha se quer 
 * incluir um novo cadastro ou exibir os cadastros existentes. 
 */

typedef struct Pessoa {
    char* nome;
    int idade;
    char* endereco;
} P;

void ler_arquivo(int n, FILE* arquivo);

int main() {
    int n;

    printf("Informe quantas pessoas deseja cadastrar: ");
    scanf("%d", &n);
    getchar(); // Após o uso de scanf, o buffer de entrada do sistema fica com o caracter '\n'. A função getchar consome este caracter limpando o buffer para uma nova leitura limpa.

    P* pessoas = malloc(n * sizeof(P));

    if (!pessoas) { // Caso não aloque, o ponteiro terá o valor NULL, que é considerado falso.
        printf("Erro de alocacao de memoria");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char buffer[256];

        printf("Pessoa %d\n", i + 1);

        printf("Nome: ");
        fgets(buffer, sizeof(buffer), stdin); // Onde salva, Comprimento máximo, De onde vem
        buffer[strcspn(buffer, "\n")] = '\0'; // Substitui o \n por \0 indicando o fim da string (atenção ao uso das aspas)
        pessoas[i].nome = malloc(strlen(buffer) + 1); // Aloca memoria para a string na struct
        strcpy(pessoas[i].nome, buffer); // Salvar em, Valor

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        getchar();

        printf("Endereco: ");
        fgets(buffer, sizeof(buffer), stdin); // Onde salva, Comprimento máximo, De onde vem
        buffer[strcspn(buffer, "\n")] = '\0'; // Substitui o \n por \0 indicando o fim da string (atenção ao uso das aspas)
        pessoas[i].endereco = malloc(strlen(buffer) + 1); // Aloca memoria para a string na struct
        strcpy(pessoas[i].endereco, buffer); // Salvar em, Valor
    }

        FILE* arquivo = fopen("cadastros.dat", "wb"); // Abre o arquivo para escrita binária

        if (!arquivo) { // Analogamente ao caso anterior, se não abrir o arquivo, será NULL
            printf("Erro ao abrir o arquivo");
            return 1;
        }

        fwrite(&n, sizeof(int), 1, arquivo);

        for (int i = 0; i < n; i++) {
            int nome_len = strlen(pessoas[i].nome) + 1;
            int endereco_len = strlen(pessoas[i].endereco) + 1;

            fwrite(&nome_len, sizeof(int), 1, arquivo);
            fwrite(pessoas[i].nome, sizeof(char), nome_len, arquivo);

            fwrite(&pessoas[i].idade, sizeof(int), 1 ,arquivo);

            fwrite(&endereco_len, sizeof(int), 1, arquivo);
            fwrite(pessoas[i].endereco, sizeof(char), endereco_len, arquivo);
        }

        fclose(arquivo);

        for (int i = 0; i < n; i++) {
            free(pessoas[i].nome);
            free(pessoas[i].endereco);
        }

        free(pessoas);

        // Abertura e leitura dos dados gravados em 'cadastros.dat'
        arquivo = fopen("cadastros.dat", "r");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo cadastros.dat");
            return 1;
        }

        ler_arquivo(n, arquivo);

    return 0;
}

void ler_arquivo(int n, FILE* arquivo) {
    fread(&n, sizeof(int), 1, arquivo);
    printf("\n--------- CADASTRO DE PESSOAS -----------\n");
    for (int i = 0; i < n; i++) {
        int nome_len, endereco_len, idade;
        char *nome, *endereco;

        fread(&nome_len, sizeof(int), 1, arquivo);
        nome = malloc(nome_len);
        fread(nome, sizeof(char), nome_len, arquivo);

        fread(&idade, sizeof(int), 1, arquivo);

        fread(&endereco_len, sizeof(int), 1, arquivo);
        endereco = malloc(endereco_len);
        fread(endereco, sizeof(char), endereco_len, arquivo);

        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Endereco: %s\n\n", endereco);
        free(nome);
        free(endereco);
    }

    fclose(arquivo);
}
