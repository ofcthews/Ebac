#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_NOMES 100  // Limite de nomes que podem ser armazenados
#define MAX_TAMANHO 100 // Tamanho m�ximo de cada nome

// Fun��o para ordenar nomes em ordem alfab�tica
void ordenar_nomes(char nomes[MAX_NOMES][MAX_TAMANHO], int contador) {
    char temp[MAX_TAMANHO];  // Vari�vel tempor�ria para troca

    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                // Troca os nomes[j] e nomes[j + 1]
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp);
            }
        }
    }
}

// Fun��o para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0, contador = 0; // Vari�veis de controle
    char nomes[MAX_NOMES][MAX_TAMANHO];  // Vetor de strings para armazenar os nomes
    int i, deletar;
    char confirmacao;

    // In�cio do menu
    do {
        printf("\n*** Cart�rio da EBAC ***\n\n");
        printf("Escolha a op��o desejada do menu:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Listar nomes em ordem alfab�tica\n");
        printf("\t5 - Limpar todos os nomes\n");
        printf("\t0 - Sair\n");
        printf("Op��o: ");
        scanf("%d", &opcao);
        limpar_buffer(); // Limpa o buffer ap�s o scanf

        switch (opcao) {
            case 1:
                if (contador < MAX_NOMES) {
                    printf("Digite o nome que deseja registrar: ");
                    fgets(nomes[contador], MAX_TAMANHO, stdin);
                    nomes[contador][strcspn(nomes[contador], "\n")] = 0; // Remove o '\n' adicionado pelo fgets
                    contador++;
                    printf("Nome registrado com sucesso!\n");
                } else {
                    printf("Limite de registros atingido!\n");
                }
                break;

            case 2:
                if (contador == 0) {
                    printf("Nenhum nome registrado.\n");
                } else {
                    printf("Nomes registrados:\n");
                    for (i = 0; i < contador; i++) {
                        printf("%d - %s\n", i + 1, nomes[i]);
                    }
                }
                break;

            case 3:
                if (contador == 0) {
                    printf("Nenhum nome registrado para deletar.\n");
                } else {
                    printf("Digite o n�mero do nome que deseja deletar: ");
                    scanf("%d", &deletar);
                    limpar_buffer(); // Limpa o buffer

                    if (deletar > 0 && deletar <= contador) {
                        printf("Tem certeza que deseja deletar o nome \"%s\"? (s/n): ", nomes[deletar - 1]);
                        scanf("%c", &confirmacao);
                        limpar_buffer(); // Limpa o buffer

                        if (confirmacao == 's' || confirmacao == 'S') {
                            for (i = deletar - 1; i < contador - 1; i++) {
                                strcpy(nomes[i], nomes[i + 1]);  // Move os nomes para cobrir o deletado
                            }
                            contador--;
                            printf("Nome deletado com sucesso!\n");
                        } else {
                            printf("Opera��o de exclus�o cancelada.\n");
                        }
                    } else {
                        printf("N�mero inv�lido!\n");
                    }
                }
                break;

            case 4:
                if (contador == 0) {
                    printf("Nenhum nome registrado para listar.\n");
                } else {
                    ordenar_nomes(nomes, contador);
                    printf("Nomes em ordem alfab�tica:\n");
                    for (i = 0; i < contador; i++) {
                        printf("%d - %s\n", i + 1, nomes[i]);
                    }
                }
                break;

            case 5:
                printf("Tem certeza que deseja limpar todos os nomes? (s/n): ");
                scanf("%c", &confirmacao);
                limpar_buffer(); // Limpa o buffer

                if (confirmacao == 's' || confirmacao == 'S') {
                    contador = 0;
                    printf("Todos os nomes foram deletados.\n");
                } else {
                    printf("Opera��o cancelada.\n");
                }
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

