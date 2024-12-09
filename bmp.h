#ifndef BMP_H
#define BMP_H

#include <stdint.h>
#include <stdio.h> // Adicionando aqui para reconhecer FILE

#define RESERVED_PIXELS 1024

// Estruturas e funções
#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_resolution;
    int32_t y_resolution;
    uint32_t colors_used;
    uint32_t important_colors;
} BMPInfoHeader;
#pragma pack(pop)

void create_bmp(const char* filename, int width, int height);
void read_bmp_headers(FILE* fp, BMPHeader* header, BMPInfoHeader* info);
void read_pixel(FILE* fp, int pixel_index, int width, int height, unsigned char* r, unsigned char* g, unsigned char* b);
void write_pixel(FILE* fp, int pixel_index, int width, int height, unsigned char r, unsigned char g, unsigned char b);

#endif
