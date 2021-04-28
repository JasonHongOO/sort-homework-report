#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "print.h"

void print(int array[], int size)
{
  for (int i = 0; i < size; ++i) printf("%d ", array[i]);
  printf("\n");
}
