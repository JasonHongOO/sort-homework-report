#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>

char *str[1000000];

void merge(char *str[100000], int l, int m, int r)
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


void mergeSort(char *str[100000], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;    //很多個迴圈疊加在一起

        mergeSort(str, l, m);       //切成一格一格，從最左邊merge到中間
        mergeSort(str, m + 1, r);   //切成一格一格，從最右邊merge到中間

        merge(str, l, m, r);        //最後兩邊在merge一次
    }
}

void print(char *str[100000], int len)
{
    for(int i = 0; i < len; i++) printf("%s\n", str[i]);
}

void freestr(char *str[100000], int len)
{
    for(int i = 0; i < len; i++) free(str[i]);
}

int main()
{

    struct  timeval start;  //timeval = time value
    struct  timeval end;
    unsigned  long diff;
    gettimeofday(&start, NULL);

    char buf[4096];
    FILE *fp;
    int idx=0;

    if((fp = fopen("dataset4.txt","r")) == NULL) {
        printf("read error\n");
        return 0;
    }

    while(fgets(buf,4096,fp) != NULL){
        int len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        str[idx] = malloc(sizeof(char)*len);
        strcpy(str[idx++],buf);
    }

    mergeSort(str,0,idx-1);
    print(str,idx);
    freestr(str,idx);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
