#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fpr;
    char buf[BUFSIZ];
    char *loadavg_file = "/proc/loadavg";
    char *tok;

    if ((fpr = fopen(loadavg_file, "r")) == NULL) {
        fprintf(stderr, "%s is not found.\n", loadavg_file);
        return 1;
    }

    if (fgets(buf, sizeof(buf), fpr) != NULL) {
        fprintf(stdout, "load average: ");
        tok = strtok(buf, " ");
        fprintf(stdout, "1min %s, ", tok);
        tok = strtok(NULL, " ");
        fprintf(stdout, "3min %s, ", tok);
        tok = strtok(NULL, " ");
        fprintf(stdout, "5min %s\n", tok);
    }
}

