#include<stdio.h>

void print_arr(int * A, int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void SelectionSort(int * A, int n){
    int min_index;
    for(int i=0; i<n-1;i++){
        min_index = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min_index]){
                min_index = j;
            }
        }
        //swap
        int temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;
        printf("Sorting %d pass\n", i+1);
        print_arr(A,n);
    }
}


int main(){
    int A[] = {1,23,15,63,18,9};
    int size = 6;
    printf("Before Sorting\n");
    print_arr(A, size);
    printf("After Sorting\n");
    SelectionSort(A, size);
    return 0;
}