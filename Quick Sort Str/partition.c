#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "partition.h"

int partition(char *str[1000000],int left,int right)
{

    int i=left;

    for(int j=left;j<right;j++) {   //把比最右邊小的數從最左邊開始一個一個排
        if(strcmp(str[j],str[right]) < 0 || strcmp(str[j],str[right]) == 0){
            char *temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
        }
    }

    char *t = str[i];    //互換後，剛好切一半，左邊都是比num[right}小的，右邊都是比num[right}大的
    str[i] = str[right];
    str[right] = t;

    return i;
}
