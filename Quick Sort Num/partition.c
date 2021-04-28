#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "partition.h"

int partition(int *num,int left,int right)
{
    int i=left;
    for(int j=left;j<right;j++) {   //把比最右邊小的數從最左邊開始一個一個排
        if(num[j]<=num[right]) {
            int t = num[i];
            num[i] = num[j];
            num[j] = t;

            i++;
        }
    }

    int t = num[i];                    //互換後，剛好切一半，左邊都是比num[right}小的，右邊都是比num[right}大的
    num[i] = num[right];
    num[right] = t;

    return i;
}
