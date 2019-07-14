#ifndef PARSER_H
#define PARSER_H

#include <stddef.h>

struct soperation {
    char opr_1[16];
    char opr_2[16];
    char op;
};

struct soperation parse_op (char *str, size_t length);
#endif
