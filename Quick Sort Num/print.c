#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "print.h"

void print(int *num, int len)
{
    for(int i = 0; i < len; i++) { printf("%d ", num[i]); }
    printf("\n");
}
