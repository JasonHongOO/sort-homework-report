#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "radixsort.h"
#include "countingSort.h"
#include "getMax.h"

void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)   countingSort(array, size, place);
}
