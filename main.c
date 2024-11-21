#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fusefs.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo.bmp> <ponto_de_montagem>\n", argv[0]);
        return 1;
    }

    fs_state.bmp_filename = argv[1];

    printf("Debugging Arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    char* fuse_argv[argc];
    memcpy(fuse_argv, argv, sizeof(char*) * argc);

    return fuse_main(argc - 1, fuse_argv + 1, &fs_oper, NULL);
}
