#include <stdio.h>
#include <string.h>
#include "nerror.h"

static const char *THRESH_STRING[] = {
    FOREACH_THRESH(GENERATE_STRING)};

void fprint_usage(FILE *fp)
{
    fprintf(fp, "\nnerror is a command line tool for logging\n");
    fprintf(fp, "\nUsage:\n");
    fprintf(fp, "nerror -l [low/medium/high] 'Logging text' - logs text\n");
    fprintf(fp, "nerror [--help/-h]                         - shows this menu\n");
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
                    if (argc <= 3)
                    {
                        NERROR(stderr, high, "You must provide a string to print");
                        NERROR(stderr, low, "Usage");
                        fprint_usage(stderr);
                        return 1;
                    }
                    NERROR(stdout, (thresh)i, argv[3]);
                    return 0;
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