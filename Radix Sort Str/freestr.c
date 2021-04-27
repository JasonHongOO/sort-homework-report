#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "freestr.h"

void freestr(char *str[1000000], int len)
{
    for(int i = 0; i < len; i++) free(str[i]);
}
