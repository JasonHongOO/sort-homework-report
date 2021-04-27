#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>

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
    i = 0;
    j = 0;
    k = l; // merged subarray
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

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;    //很多個迴圈疊加在一起

        mergeSort(arr, l, m);       //切成一格一格，從最左邊merge到中間
        mergeSort(arr, m + 1, r);   //切成一格一格，從最右邊merge到中間

        merge(arr, l, m, r);        //最後兩邊在merge一次
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++) printf("%d ", A[i]);
}

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

    if((fp = fopen("dataset3.txt","r")) == NULL) {
        printf("read error\n");
        return 0;
    }

    while(fgets(buf,4096,fp) != NULL){
        int len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        number[idx++] = atoi(buf);
    }

    mergeSort(number, 0, idx - 1);
    printArray(number, idx);
    free(number);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
