#include<stdio.h>

void print_arr(int * A, int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void merge(int A[], int lo, int mid, int hi){
    int i,j,k,B[100];
    i = lo; j=mid+1; k=lo;

    while(i<=mid && j<=hi){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++; k++;
        }
        else{
            B[k] = A[j];
            j++; k++;
        }
    }

    while(i<=mid){
        B[k] = A[i];
        i++; k++;
    }

    while(j<=hi){
        B[k] = A[j];
        j++; k++;
    }

    for(int i=lo;i<hi+1;i++){
        A[i] = B[i];
    }

}

void mergeSort(int A[], int lo, int hi){
    if(lo<hi){
         int mid = (lo+hi)/2;
         mergeSort(A, lo, mid);
         mergeSort(A,mid+1,hi);
         merge(A,lo,mid,hi);
    }
}

int main(){
    int A[] = {1,23,15,63,18,9};
    int size = 6;
    printf("Before Sorting\n");
    print_arr(A, size);
    printf("After Sorting\n");
    mergeSort(A, 0, size-1);
    print_arr(A, size);
    return 0;
}