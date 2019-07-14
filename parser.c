#include "parser.h" 
#include <string.h>

int is_digit (char c) 
{
    switch (c) {
        case '0' :
        case '1' :
        case '2' :
        case '3' :
        case '4' :
        case '5' :
        case '6' :
        case '7' :
        case '8' :
        case '9' :
            return 1;
        default:
            return 0;
    }
}

#define build_struct(sop,opr_1,opr_2,op)    \
    do {                                    \
        strcpy (sop.opr_1, opr_1);          \
        strcpy (sop.opr_2, opr_2);          \
        sop.op = op;                        \
        return sop;                         \
    } while (0)

struct soperation parse_op (char *str, size_t length) 
{
    struct soperation sop;

    char opr_1[16] = { 0 }; char *opr_1_p = opr_1;
    char opr_2[16] = { 0 }; char *opr_2_p = opr_2;
    char op;

    char *p = str;

    while (is_digit (*p) && p < (str + length))
        *opr_1_p++ = *p++; 

    op = *p; // The operand

    if (*p == '!')
        goto BUILD_STRUCT;
    
    p++;

    while (is_digit (*p) && p < (str + length))
        *opr_2_p++ = *p++;

BUILD_STRUCT:
    build_struct (sop, opr_1, opr_2, op);
}
