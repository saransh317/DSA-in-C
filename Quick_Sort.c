#include<stdio.h>

void print_arr(int * A, int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while (A[i] <= pivot){i++;}
        while (A[j] > pivot){j--;}

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}

int main(){
    int A[] = {1,23,15,63,18,9};
    int size = 6;
    printf("Before Sorting\n");
    print_arr(A, size);
    printf("After Sorting\n");
    quickSort(A, 0, size-1);
    print_arr(A, size);
    return 0;
}