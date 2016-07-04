#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fpr;
    char buf[BUFSIZ];
    char *loadavg_file = "/proc/loadavg";
    char *tok;
    char la_1min[5];
    char la_3min[5];
    char la_5min[5];

    if ((fpr = fopen(loadavg_file, "r")) == NULL) {
        fprintf(stderr, "%s is not found.\n", loadavg_file);
        return 1;
    }

    if (fgets(buf, sizeof(buf), fpr) != NULL) {
        tok = strtok(buf, " ");
        strcpy(la_1min, tok);
        tok = strtok(NULL, " ");
        strcpy(la_3min, tok);
        tok = strtok(NULL, " ");
        strcpy(la_5min, tok);

        if (strcmp(argv[argc - 1], "--csv") == 0) {
            fprintf(stdout, "%s,%s,%s\n", la_1min, la_3min, la_5min);
        } else if (strcmp(argv[argc - 1], "--json") == 0) {
            fprintf(stdout, "{\"1min\":\"%s\",\"3min\":\"%s\",\"5min\":\"%s\"}\n", la_1min, la_3min, la_5min);
        } else {
            fprintf(stdout, "load average: 1min %s, 3min %s, 5min %s\n", la_1min, la_3min, la_5min);
        }
    }
}

