#ifndef FUSEFS_H
#define FUSEFS_H

#define FUSE_USE_VERSION 31

#include <fuse3/fuse.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char* bmp_filename;
    FILE* bmp;
} FSState;

extern FSState fs_state;
extern struct fuse_operations fs_oper;

#endif
