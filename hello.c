#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("fail");
        return 1;
    }
    int cnt = 0;
    //file
    //total number of data ?? (30)
    //data data data
    //...
    //...
    //total number of data i wnt t knw ? (3) 
    int tot;
    int num;
    fscanf(fp, "%d", &tot);
    int *data;
    data = (int *)malloc(sizeof(int) * tot);
    for(int i = 0; i < tot; i++){
        fscanf(fp, "%d", data[i]);
    }
    fscanf(fp, "%d", &num);
    int *arr;
    arr = (int *)malloc(sizeof(int) * num);
    for(int i = 0;i<num;i++){
        scanf("%d", arr[i]);
    }
    for(int i = 0; i < tot; i++){
        for(int j =0; j<tot; j++){
            if(data[i] == arr[j]){
            printf("%d", i);
            }
        }
    }
    free(data);
    free(arr);
    fclose(fp);
    return 0;
}