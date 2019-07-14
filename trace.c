#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trace.h"

void savop(char op, int opg, int opd, long int res){
    FILE* f; 
    f=fopen("track.trc","a");
    fprintf(f, "%c\t%d\t%d\t%d\n", op, opg, opd, res);    
    fclose(f);
    
}

void lireop(tabl* x){
    FILE* f;
    /*tabl lop;*/
    f=fopen("track.trc","r");

    if(!f)
        return;

    char *line = NULL;
    size_t n = 0;
    int i = 0;
    int cont = 1;

    rewind(f);

    while (getline (&line, &n, f) != -1) {
        if(line)
            printf ("%s\n", line);        
    }             
     
    fclose(f);     
}

int main () {

    operation op;
    char *line = NULL;
    size_t n = 0;
    int i = 0;
    int cont = 1;

    while (getline (&line, &n, stdin) != -1 && cont) 
    {   
        char *p;

        if (strstr(line, "afficher")) {
            puts ("execing afficher");              
            tabl x;
            lireop(&x);
            return 0;
        }
       
        switch (i) {
            case 0: // operande
                op.o = line[0];
                break;
            case 1:
                op.g = atoi (line);
                break;
            case 2:
                op.d = atoi (line);
                break;
            case 3:
                op.r = atoi (line);
                break;
            default:
                cont = 0;
                break;
        }
        
        i++;        
    } 

    savop (op.o, op.g, op.d, op.r);

    char *str = op.o == 's' ? "sommme" : (op.o == 'p' ? "produit" : "factoriel");  

    printf ("%s\t%d\t%d\t=\t%d\n", str, op.g, op.d, op.r);
}
