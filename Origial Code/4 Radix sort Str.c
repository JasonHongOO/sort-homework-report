#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>

void freestr(char *str[100000], int len)
{
    for(int i = 0; i < len; i++) free(str[i]);
}

void countingSort(char *array[100000], int size, int idx)
{
  char **output = malloc(sizeof(char *) * 1000000);;

  //個數是計算該位數中，是相同數字的有幾個
  int count[26]={0};

  for (int i = 0; i < size; i++)  count[array[i][idx]-'a']++; //計算每個數字出現的次數  數字範圍 0 到 9
  for (int i = 1; i < 26; i++)    count[i] += count[i - 1];         //把整排陣列都加上前面一格  0的數字就會最小 9的數字就會最大
  for (int i = size - 1; i >= 0; i--) {
      output[count[array[i][idx]-'a']-1] = array[i];        //有一個以上時，會先從最後一格開始一個一個放入，放回來，並且第一個位置為0   ex:有三個，count[該數]會等於3，則先放a[2] -> a[1] -> a[0]每次減一
      count[array[i][idx]-'a']--;
  }

  for (int i = 0; i < size; i++)   array[i] = output[i];
  free(output);
}

void radixsort(char *str[100000], int size ,int maxlen)
{
  for (int count = 0; count < maxlen; count++)   {countingSort(str, size, count);}
}

void print(char *str[100000], int len)
{
    for(int i = 0; i < len; i++) printf("%s\n", str[i]);
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
    int maxlen = 0;
    for(int i=0;i<idx;i++) {
        int len = strlen(str[i]);
        if(len > maxlen) maxlen = len;
    }
    radixsort(str, idx,maxlen);
    print(str, idx);
    freestr(str,idx);
    free(str);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
