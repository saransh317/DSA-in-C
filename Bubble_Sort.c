#include<stdio.h>
#include<stdlib.h>

void print_arr(int * A, int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void BubbleSort(int * A, int n){
    int isSort = 0;
    for(int i=0;i<n-1;i++){
        isSort = 1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSort=0;
            }
        }
        if(isSort){break;}
    }
}

int main(){
    int A[] = {1,3,5,6,8,9};
    int size = 6;
    printf("Before Sorting\n");
    print_arr(A, size);
    printf("After Sorting\n");
    BubbleSort(A, size);
    print_arr(A, size);


    return 0;
}