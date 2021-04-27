#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "radixsort.h"

void radixsort(char *str[1000000], int size ,int maxlen)
{
  for (int count = 0; count < maxlen; count++)   countingSort(str, size, count);
}
