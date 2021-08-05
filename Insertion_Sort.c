#include<stdio.h>

void print_arr(int * A, int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void InsertionSort(int * A, int n){
    for(int i=1;i<n;i++){
        int key = A[i];
        int j = i-1;
        while(A[j]>key && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {1,23,15,63,18,9};
    int size = 6;
    printf("Before Sorting\n");
    print_arr(A, size);
    printf("After Sorting\n");
    InsertionSort(A, size);
    print_arr(A, size);
    return 0;
}