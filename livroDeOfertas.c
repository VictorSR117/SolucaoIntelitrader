#include <stdio.h>
#include <stdlib.h>

#define MAX_OFFERS 100

typedef struct {
    double value;
    int quantity;
} Offer;

void printOrderBook(Offer book[], int size) {
    printf("\n");
    for (int iterator = 0; iterator < size; iterator++) printf("%d,%.2f,%d\n", iterator + 1, book[iterator].value, book[iterator].quantity);
}

void insertOffer(Offer book[], int *size, int position, double value, int quantity) {
    for (int iterator = *size; iterator >= position; iterator--) book[iterator] = book[iterator - 1];

    book[position - 1].value = value;
    book[position - 1].quantity = quantity;
    (*size)++;
}

void modifyOffer(Offer book[], int position, double value, int quantity) {
    if (value != 0) book[position - 1].value = value;
    if (quantity != 0) book[position - 1].quantity = quantity;
}

void deleteOffer(Offer book[], int *size, int position) {
    for (int iterator = position - 1; iterator < *size - 1; iterator++) book[iterator] = book[iterator + 1];
    (*size)--;
}

int main() {
    int numberOfOperations;
    Offer book[MAX_OFFERS];
    int bookSize = 0;

    printf("Digite o número de operações a serem realizadas:\n");
    if ((scanf("%d", &numberOfOperations) != 1 || numberOfOperations <= 0)) {
        fprintf(stderr, "Erro ao ler o número de operações.\n");
        return EXIT_FAILURE;
    }

    printf("\nInstruções para entrada de dados:\n");
    printf("Digite as operações no formato: posição,ação,valor,quantidade sem espaços em branco e com quebra de linhas\n");
    printf("Exemplos:\n");
    printf("1,0,15.4,50\n");
    printf("2,0,15.5,50\n");
    printf("2,2,0,0\n");
    printf("\nLegenda das Ações:\n");
    printf("0 = INSERIR\n");
    printf("1 = MODIFICAR\n");
    printf("2 = DELETAR\n");
    printf("\n");
    printf("Digite as operações: \n\n");

    for (int iterator = 0; iterator < numberOfOperations; iterator++) {
        int position, action, quantity;
        double value;

        if (scanf("%d,%d,%lf,%d", &position, &action, &value, &quantity) != 4) {
            fprintf(stderr, "Erro ao ler a atualização.\n");
            return EXIT_FAILURE;
        }

        if (position < 1 || position > bookSize + 1) {
            fprintf(stderr, "Posição inválida: %d\n", position);
            continue;
        }

        switch (action) {
            case 0:  // INSERT
                (bookSize < MAX_OFFERS) ? insertOffer(book, &bookSize, position, value, quantity) : fprintf(stderr, "Livro de ofertas cheio.\n");
                break;
            case 1:  // MODIFY
                (position <= bookSize) ? modifyOffer(book, position, value, quantity) : fprintf(stderr, "Posição inválida para modificação: %d\n", position);
                break;
            case 2:  // DELETE
                (position <= bookSize) ? deleteOffer(book, &bookSize, position) : fprintf(stderr, "Posição inválida para deletar: %d\n", position);
                break;
            default:
                fprintf(stderr, "Ação inválida: %d\n", action);
                break;
        }
    }

    printOrderBook(book, bookSize);
    return EXIT_SUCCESS;
}