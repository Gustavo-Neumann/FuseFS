#include "bmp.h"
#include "stego.h"
#include <stdio.h>
#include <string.h>

int main() {
    const char* filename = "test_image.bmp";
    FILE* bmp = fopen(filename, "rb+");
    if (!bmp) {
        perror("Erro ao abrir o arquivo BMP");
        return 1;
    }

    // Dados para esconder e recuperar
    const char* message = "Hello, BMP!";
    char recovered_message[20] = {0}; // Buffer para recuperação

    printf("Escondendo mensagem...\n");
    hide_data(bmp, message, strlen(message), 0); // Esconde no início do BMP

    printf("Recuperando mensagem...\n");
    retrieve_data(bmp, recovered_message, strlen(message), 0); // Recupera do início do BMP

    printf("Mensagem recuperada: %s\n", recovered_message);

    fclose(bmp);
    return 0;
}
