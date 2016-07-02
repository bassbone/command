#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void mew();

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
        fprintf(stderr, "$sというファイルが見つかりません\n", argv[argc-1]);
    } else {
    }

    srand((unsigned)time(NULL));
    if (rand() % 2 == 1) {
        mew();
        return 0;
    } else {
        while (fgets(buf, sizeof(buf), fpr)!=NULL) {
            fprintf(stdout, "%s", buf);
        }
    }
}

void mew()
{
    int cnt;
    int cnt2;

    for (cnt = 1; cnt <= 30; cnt++) {
        printf("\r");
        for (cnt2 = 0; cnt2 < cnt; cnt2++) {
            printf(" ");
        }
        printf("`(=^‥^)");
        fflush(stdout);
        usleep(50000);
    }
    printf(" < mew, mew, mew.\n");
}

