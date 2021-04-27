#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "mergeSort.h"

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;    //很多個迴圈疊加在一起

        mergeSort(arr, l, m);       //切成一格一格，從最左邊merge到中間
        mergeSort(arr, m + 1, r);   //切成一格一格，從最右邊merge到中間

        merge(arr, l, m, r);        //最後兩邊在merge一次
    }
}
