#ifndef H_NERROR
#define H_NERROR

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#define FOREACH_THRESH(THRESH) \
    THRESH(low)                \
    THRESH(medium)             \
    THRESH(high)

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

typedef enum thresh
{
    FOREACH_THRESH(GENERATE_ENUM)
} thresh;

void _print_prefix(FILE *f, thresh t, int line, const char *file, const char *function);

// F is file, X is threshold
#define NERROR(f, x, ...)                              \
    _print_prefix(f, x, __LINE__, __FILE__, __func__); \
    fprintf(f, __VA_ARGS__);                           \
    fprintf(f, "\033[0m\n")
// PNERROR prints to stdout
#define PNERROR(x, ...) NERROR(stdout, x, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
