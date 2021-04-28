#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main() {

    char A[100][101];
    int N = 1000000;

    FILE *output;
    output=fopen("dataset2.txt","w");

    for(int i=0;i<N;i++){
        for(int j=0;j<100;j++){
            A[1][j] = (rand() % 26) +97;
        }
        fprintf(output,"%s\n",A[1]);
    }

    fclose(output);
    return 0;
}
