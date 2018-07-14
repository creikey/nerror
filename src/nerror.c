#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <malloc.h>
#include <assert.h>
#include <stdint.h>
#include "conf.h"
#include "nerror.h"

#ifdef __cplusplus
extern "C" {
#endif

char *_time_int(int in_digit)
{
    size_t t_return_size = 3;
    char *to_return = malloc(sizeof *to_return * t_return_size);
    if (in_digit >= 10)
    {
        snprintf(to_return, t_return_size, "%d", in_digit);
    }
    else
    {
        snprintf(to_return, t_return_size, "%d", in_digit);
        to_return[1] = to_return[0];
        to_return[0] = '0';
        to_return[2] = '\0';
    }
    return to_return;
}

void _print_prefix(FILE *f, thresh t, int line, const char *file, const char *function)
{
#ifdef INCLUDE_DATE
    time_t ti = time(NULL);
    struct tm tm = *localtime(&ti);
    fprintf(f, "%d-%d-%d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
#endif // INCLUDE_DATE
#ifdef INCLUDE_TIME
#ifndef INCLUDE_DATE
    time_t ti = time(NULL);
    struct tm tm = *localtime(&ti);
#endif // INCLUDE_DATE
    char *hours = _time_int(tm.tm_hour);
    char *mins = _time_int(tm.tm_min);
    char *secs = _time_int(tm.tm_sec);
    fprintf(f, "%s:%s:%s ", hours, mins, secs);
    free(hours);
    free(mins);
    free(secs);
#endif // INCLUDE_TIME
#ifdef INCLUDE_POSITION
    fprintf(f, "(%s, %d) ", file, line);
#endif // INCLUDE_POSITION
#ifdef INCLUDE_FUNCTION
    fprintf(f, "[%s] ", function);
#endif // INCLUDE_FUNCTION
    switch (t)
    {
    case low:
        fprintf(f, "%s%s", LOW_THRESH_COLOR, LOW_THRESH_MESSAGE);
        break;
    case medium:
        fprintf(f, "%s%s", MED_THRESH_COLOR, MED_THRESH_MESSAGE);
        break;
    case high:
        fprintf(f, "%s%s", HIH_THRESH_COLOR, HIH_THRESH_MESSAGE);
        break;
    }
}

#ifdef __cplusplus
}
#endif
