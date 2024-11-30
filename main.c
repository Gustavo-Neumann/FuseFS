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

    // Reorganizar os argumentos para o FUSE
    char* fuse_argv[argc + 1];
    fuse_argv[0] = argv[0];             // Executável
    fuse_argv[1] = argv[2];             // Ponto de montagem
    fuse_argv[2] = "-o";                // Opções do FUSE
    fuse_argv[3] = "default_permissions,allow_other"; // Opções FUSE
    fuse_argv[4] = NULL;                // Finaliza com NULL

    // Inicia o FUSE
    return fuse_main(4, fuse_argv, &fs_oper, NULL);
}
