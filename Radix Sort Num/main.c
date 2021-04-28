#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>
#include "countingSort.h"
#include "radixsort.h"
#include "getMax.h"
#include "print.h"

int main()
{

    struct  timeval start;  //timeval = time value
    struct  timeval end;
    unsigned  long diff;
    gettimeofday(&start, NULL);

    int *number = malloc(sizeof(int) * 1000000);

    char buf[4096];
    FILE *fp;
    int idx=0;

    if((fp = fopen("dataset1.txt","r")) == NULL) {
        printf("read error\n");
        return 0;
    }
    //printf("enter 1\n");
    while(fgets(buf,4096,fp) != NULL){
        int len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        number[idx++] = atoi(buf);
    }
    //printf("enter 2\n");
    radixsort(number, idx);
    print(number, idx);
    free(number);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
