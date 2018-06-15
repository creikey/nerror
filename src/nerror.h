#ifndef H_NERROR
#define H_NERROR

#include <stdio.h>

typedef enum thresh { low, medium, high } thresh;

void _print_prefix(FILE *f, thresh t);

// F is file, X is threshold
#define NERROR(f, x,...) _print_prefix(f,x); fprintf(f, __VA_ARGS__); fprintf(f, "\033[0m\n")
// PNERROR prints to stdout
#define PNERROR(x, ...) NERROR(stdout, x, __VA_ARGS__)

#endif