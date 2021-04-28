#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "quicksort.h"
#include "partition.h"

void quicksort(int *num,int left,int right)
{
    if(left<right) {                                              //一直不斷切，切到最後，一個區塊只有3個數或以下時，就會排序完成
        int q = partition(num ,left ,right);                      //切兩半
        quicksort(num,left,q-1);                                  //左半部不斷切
        quicksort(num,q+1,right);                                 //右半部不斷切
    }
}
