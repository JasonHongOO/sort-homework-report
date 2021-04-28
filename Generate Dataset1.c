#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main() {

    int A[100];
    int N = 1000000;

    FILE *output;
    output=fopen("dataset1.txt","w");

    for(int i=0;i<N;i++){
        A[1] = rand();
        fprintf(output,"%d\n",A[1]);
    }

    fclose(output);
    return 0;
}
