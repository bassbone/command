#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
    if (strcmp(argv[argc - 1], "pi") == 0) {
        fprintf(stdout, "3.14\n");
        return 0;
    }
}

