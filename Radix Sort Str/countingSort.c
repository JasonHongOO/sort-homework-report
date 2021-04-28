#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "countingSort.h"

void countingSort(char *array[1000000], int size, int idx)
{
  char **output = malloc(sizeof(char *) * 1000000);;

  //個數是計算該位數中，是相同數字的有幾個
  int count[26]={0};

  for (int i = 0; i < size; i++)  count[array[i][idx]-'a']++; //計算每個數字出現的次數  數字範圍 0 到 9
  for (int i = 1; i < 26; i++)    count[i] += count[i - 1];         //把整排陣列都加上前面一格  0的數字就會最小 9的數字就會最大
  for (int i = size - 1; i >= 0; i--) {
      output[count[array[i][idx]-'a']-1] = array[i];        //有一個以上時，會先從最後一格開始一個一個放入，放回來，並且第一個位置為0   ex:有三個，count[該數]會等於3，則先放a[2] -> a[1] -> a[0]每次減一
      count[array[i][idx]-'a']--;
  }

  for (int i = 0; i < size; i++)   array[i] = output[i];
  free(output);
}
