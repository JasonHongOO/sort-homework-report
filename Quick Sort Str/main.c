#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>
#include "partition.h"
#include "quicksort.h"
#include "print.h"
#include "freestr.h"

int main()
{

    struct  timeval start;  //timeval = time value
    struct  timeval end;
    unsigned  long diff;
    gettimeofday(&start, NULL);

    char **str = malloc(sizeof(char *) * 1000000);
    char buf[4096];
    FILE *fp;
    int idx=0;

    if((fp = fopen("dataset2.txt","r")) == NULL) {
        printf("read error\n");
        return 0;
    }

    while(fgets(buf,4096,fp) != NULL){
        int len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        str[idx] = malloc(sizeof(char)*len);
        strcpy(str[idx++],buf);
    }

    quicksort(str,0,idx-1);
    print(str, idx);
    freestr(str,idx);
    free(str);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
