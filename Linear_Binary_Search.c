#include<stdio.h>
#include<stdlib.h>

int linear_search(int arr[], int element, int size){
    for(int i=0;i<size;i++){
        if(arr[i]==element){return i;}
    }
    return -1;
}

int binary_search(int arr[], int element, int size){
    int mid, low=0, high=size-1;
    while(low<high){
        mid = (low+high)/2;
        if(arr[mid]==element) {return mid;}
        else if(arr[mid]>element){high = mid-1;}
        else{low = mid+1;}
    }
    return -1;
}

int main(){
    int arr[] = {3,5,4,31,32,58,125,284,489,677,987,3811,9020,13222};
    int element=3, capacity = 100, size = sizeof(arr)/sizeof(arr[0]);
    //int searchIndex = linear_search(arr, element, size);
    int searchIndex = binary_search(arr, element, size);
    printf("'%d' Element found at = %d\n", element, searchIndex);
    return 0;
}