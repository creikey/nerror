#include <stdio.h>
#include <string.h>
#include "nerror.h"

void fprint_usage(FILE *fp)
{
    fprintf(fp, "nerror is a command line tool for logging\n");
    fprintf(fp, "-- USAGE\n");
    fprintf(fp, "nerror -l [low/medium/high] 'Logging text'\n");
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        NERROR(stderr, low, "Usage");
        fprint_usage(stderr);
        return 1;
    }
    else
    {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            fprint_usage(stdout);
            return 0;
        }
        if (strcmp(argv[1], "-l") == 0)
        {
            for (int i = 0; i < sizeof(THRESH_STRING) / sizeof(THRESH_STRING[0]); i++)
            {
                if (strcmp(argv[2], THRESH_STRING[i]) == 0)
                {
                    NERROR(stdout, (thresh)i, argv[3]);
                }
            }
            NERROR(stderr, high, "Unrecognized threshold %s", argv[2]);
            NERROR(stderr, low, "Usage");
            fprint_usage(stderr);
            return 1;
        }
        NERROR(stderr, high, "Unrecognized option %s", argv[1]);
        NERROR(stderr, low, "Usage");
        fprint_usage(stderr);
        return 1;
    }
}