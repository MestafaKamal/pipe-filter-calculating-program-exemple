#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main ()
{
    char buffer[256];
    char *prog;
    FILE *wfd;

    int a = 0;

    printf ("Entrer l'operation ou taper afficher pour lire track:");
    fgets (buffer, sizeof(buffer) - 1, stdin);

    if (strstr(buffer, "afficher")) 
        prog = "./trace";
   else 
        prog = "./calcul";

    wfd = popen (prog, "w");

    if (wfd == NULL) {
        return -1;
    }

    fprintf(wfd, "%s", buffer);
    pclose (wfd);
}
