#include <stdio.h>
#include "nerror.h"

int main(int argc, char ** argv)
{
    PNERROR(low, "testing");
    PNERROR(medium, "more");
    PNERROR(high, "things");
}