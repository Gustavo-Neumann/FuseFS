#ifndef STEGO_H
#define STEGO_H

#include <stdio.h>
#include <stdint.h>

// Funções de esteganografia
void hide_data(FILE* bmp, const void* data, size_t size, uint32_t offset);
void retrieve_data(FILE* bmp, void* data, size_t size, uint32_t offset);

#endif
