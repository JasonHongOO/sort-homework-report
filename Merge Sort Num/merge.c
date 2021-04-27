#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "merge.h"

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(sizeof(int) * 500000);
    int *R = malloc(sizeof(int) * 500000);

    for (i = 0; i < n1; i++)  L[i] = arr[l + i];
    for (j = 0; j < n2; j++)  R[j] = arr[m + 1 + j];

    //初始化
    i = 0; j = 0; k = l; // merged subarray
    while (i < n1 && j < n2) {         //比對，比較小的先放進來
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //把剩下的放入
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
