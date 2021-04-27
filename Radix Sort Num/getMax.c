#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "getMax.h"

int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)   if (array[i] > max)  max = array[i];
  return max;
}
