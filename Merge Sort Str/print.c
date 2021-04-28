#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "print.h"

void print(char *str[1000000], int len)
{
    for(int i = 0; i < len; i++) printf("%s\n", str[i]);
}
