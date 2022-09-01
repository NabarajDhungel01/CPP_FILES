#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){ 
    if (argc < 2) {
        fprintf(stderr, "usage: %s File\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    char buff[BUFSIZ];

    while(fgets(buff, BUFSIZ - 1, fp) != NULL)
    {

        printf ("%s\n", buff); /* ...such as show it on the screen */
    }
    fclose(fp);  /* close the file */
}
