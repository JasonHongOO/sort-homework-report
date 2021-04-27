#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<sys/time.h>

int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)   if (array[i] > max)  max = array[i];
  return max;
}

void countingSort(int array[], int size, int place)
{
  int *output = malloc(sizeof(int) * 1000000);
  //個數是計算該位數中，是相同數字的有幾個
  int count[10]={0};

  for (int i = 0; i < size; i++)  count[(array[i] / place) % 10]++; //計算每個數字出現的次數  數字範圍 0 到 9
  for (int i = 1; i < 10; i++)    count[i] += count[i - 1];         //把整排陣列都加上前面一格  0的數字就會最小 9的數字就會最大
  for (int i = size - 1; i >= 0; i--) {
      output[count[(array[i] / place) % 10] - 1] = array[i];        //有一個以上時，會先從最後一格開始一個一個放入，放回來，並且第一個位置為0   ex:有三個，count[該數]會等於3，則先放a[2] -> a[1] -> a[0]每次減一
      count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)   array[i] = output[i];
  free(output);
}

void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)   countingSort(array, size, place);
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i) printf("%d ", array[i]);
  printf("\n");
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
    //printf("enter 1\n");
    while(fgets(buf,4096,fp) != NULL){
        int len = strlen(buf);
        if(buf[len-1] == '\n') buf[len-1] = '\0';
        number[idx++] = atoi(buf);
    }
    //printf("enter 2\n");
    radixsort(number, idx);
    printArray(number, idx);
    free(number);

    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;  // 秒先*1000000 在加毫秒 之後除1000000就直接會是答案
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0); // %ld=long // µs = 毫秒 10的負6次方秒

    return 0;
}
