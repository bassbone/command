#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void mew();
void strrep();

int main (int argc, char *argv[])
{
    FILE *fpr;
    char buf[BUFSIZ];

    if (argc < 2) {
        fpr = stdin;
    } else if (strcmp(argv[argc - 1], "--mew") == 0) {
        mew();
        return 0;
    } else if (strcmp(argv[argc - 1], "--help") == 0) {
        fprintf(stdout, "usage: cat [file or stdin]\n");
        return 0;
    } else if ((fpr = fopen(argv[argc - 1], "r"))==NULL) {
        fprintf(stderr, "%s is not found.\n", argv[argc-1]);
        return 1;
    }

    srand((unsigned)time(NULL));
    if (rand() % 3 == 1) {
        mew();
        return 0;
    } else {
        while (fgets(buf, sizeof(buf), fpr)!=NULL) {
            fprintf(stdout, "%s", buf);
        }
    }
}

/*
 * mew
 */
void mew()
{
    int cnt;
    int cnt2;

    for (cnt = 1; cnt <= 30; cnt++) {
        printf("\r");
        strrep(" ", cnt);
        printf("`(=^‥^)");
        fflush(stdout);
        usleep(50000);
    }
    printf(" < mew, mew, mew.\n");
}

/*
 * strrep
 * repeat string num times
 */
void strrep(char *str, int num)
{
    int cnt;
    for (cnt = 0; cnt < num; cnt++) {
        printf(str);
    }
}
