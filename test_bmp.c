#include "bmp.h"
#include <stdio.h>

int main() {
    const char* filename = "test_image.bmp";
    int width = 100, height = 100;

    printf("Criando imagem BMP...\n");
    create_bmp(filename, width, height);

    FILE* bmp = fopen(filename, "rb+");
    if (!bmp) {
        perror("Erro ao abrir o arquivo BMP");
        return 1;
    }

    unsigned char r, g, b;
    printf("Escrevendo pixels...\n");
    write_pixel(bmp, 0, width, height, 255, 0, 0); // Vermelho no pixel 0
    write_pixel(bmp, 1, width, height, 0, 255, 0); // Verde no pixel 1
    write_pixel(bmp, 2, width, height, 0, 0, 255); // Azul no pixel 2

    printf("Lendo pixels...\n");
    read_pixel(bmp, 0, width, height, &r, &g, &b);
    printf("Pixel 0: R=%d, G=%d, B=%d\n", r, g, b);

    read_pixel(bmp, 1, width, height, &r, &g, &b);
    printf("Pixel 1: R=%d, G=%d, B=%d\n", r, g, b);

    read_pixel(bmp, 2, width, height, &r, &g, &b);
    printf("Pixel 2: R=%d, G=%d, B=%d\n", r, g, b);

    fclose(bmp);
    return 0;
}
