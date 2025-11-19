#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* fp = fopen("any.txt", "r");
    if (fp == NULL){
        printf("fail");
        return 1;
    }
    int data[30][30];
    int cnt = 0;
    //file
    //total number of data ?? (30)
    //data data data
    //...
    //...
    //total number of data i wnt t knw ? (3) 
    int tot;
    int num;
    fscanf(fp, "%d", &tot)
    int *arr;
    arr = (int *)malloc(sizeof(int) * tot);
    for(int i = 0; i < tot; i++){
        fscanf(fp, "%d", data[i % 10][i / 10]);
    }
    fscanf(fp, "%d", &num);
    for(int i = 0;i<num;i++){
        scanf("%d", arr[i]);
    }
    for(int i = 0; i < tot; i++){
        for(int j =0; j<tot; j++){
            if(data[i % 10][i / 10] == arr[j]){
            printf("%d", i);
            }
        }
    }

    free(arr);
    fclose(fp);
    return 0;
}