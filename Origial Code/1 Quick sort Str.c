#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>

int partition(char *str[100000],int left,int right)
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

void quicksort(char *str[100000],int left,int right)
{
    if(left<right) {                                              //一直不斷切，切到最後，一個區塊只有3個數或以下時，就會排序完成
        int q = partition(str,left ,right);                      //切兩半
        quicksort(str,left,q-1);                                  //左半部不斷切
        quicksort(str,q+1,right);                                 //右半部不斷切
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
