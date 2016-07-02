#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
    FILE *fpr;
    char buf[BUFSIZ];

    if (argc < 2) {
        fpr = stdin;
    } else if (strcmp(argv[argc-1],"--help") == 0) {
        fprintf(stdout, "usage: cat [file or stdin]\n");
        return 0;
    } else if ((fpr = fopen(argv[argc-1],"r"))==NULL) {
        fprintf(stderr, "$sというファイルが見つかりません\n", argv[argc-1]);
    } else {
    }

    while (fgets(buf, sizeof(buf), fpr)!=NULL) {
        fprintf(stdout, "%s", buf);
    }
}

