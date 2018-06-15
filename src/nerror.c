#include <stdio.h>
#include <time.h>
#include "conf.h"
#include "nerror.h"

void _print_prefix(FILE *f, thresh t)
{
    #ifdef INCLUDE_DATE
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(f, "%d-%d-%d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    #endif // INCLUDE_DATE
    #ifdef INCLUDE_TIME
    #ifndef INCLUDE_DATE
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    #endif // INCLUDE_DATE
    fprintf(f, "%d:%d:%d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
    #endif // INCLUDE_TIME
    switch(t) {
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