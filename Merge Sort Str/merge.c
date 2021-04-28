#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "merge.h"

void merge(char *str[1000000], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    char **L = malloc(sizeof(char *) * 500000);
    char **R = malloc(sizeof(char *) * 500000);

    for (i = 0; i < n1; i++)  L[i]=str[l + i];
    for (j = 0; j < n2; j++)  R[j]=str[m + 1 + j];

    //初始化
    i = 0;
    j = 0;
    k = l; // merged subarray
    while (i < n1 && j < n2) {         //比對，比較小的先放進來
        if (strcmp(L[i],R[j]) < 0 || strcmp(L[i],R[j]) == 0) {
            str[k]=L[i];
            i++;
        }
        else {
            str[k]=R[j];
            j++;
        }
        k++;
    }

    //把剩下的放入
    while (i < n1) {
        str[k]=L[i];
        i++;
        k++;
    }

    while (j < n2) {
        str[k]=R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
