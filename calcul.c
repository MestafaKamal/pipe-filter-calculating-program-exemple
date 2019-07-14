#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

typedef struct 
{ 
    char o;
    int g;
    int d;
    long int r;
} operation;

void savop (char opr, int a, int b, int r) 
{
    FILE *wfd = popen("./trace", "w");
    
    if (wfd == NULL)
        return;

    fprintf (wfd, "%c\n", opr);
    fprintf (wfd, "%d\n", a);
    fprintf (wfd, "%d\n", b);
    fprintf (wfd, "%d\n", r);

    pclose (wfd); 
}

long int somme(int c, int d){
int a,b;
a=c; b=d;
savop('s',a,b,a+b);
return c+d;
}

long int prod(int c, int d){
int a,b;
a=c; b=d;
savop('p',a,b,a*b);
return c*d;
}

long int fact(int n){
 long int r;
 int x=n;
 if (n<=1) r=1;
    else r= n*fact(n-1);
savop('f',x,0,r);
 return (r);
}

int main () {
    char buffer[256];

    memset (buffer, 0, 256);
    fgets (buffer, 255, stdin);

    struct soperation sop = parse_op (buffer, strlen(buffer));

    switch (sop.op) 
    {
        case '+':
            somme(atoi(sop.opr_1), atoi(sop.opr_2));
            break;
        case '*':
            prod(atoi(sop.opr_1), atoi(sop.opr_2));
            break;
        case '!':  
            fact(atoi(sop.opr_1));
            break;
        default:
            break;
    }
}
