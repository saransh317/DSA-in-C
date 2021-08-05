#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int size){
    //Traversal
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//For insertion
int Reg_Insertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1;
    }
    else{
        //Opening up space for new element
        for(int i=size-1;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index] = element;
        return 1;    
    }
}

//For deletion
int Deletion(int arr[], int size, int index){
    if(index>size){
        return -1;
    }
    else{
        for(int i=index;i<size-1;i++){
            arr[i] = arr[i+1]; //2,3,4,5 -> 2,4,4,5 -> 2,4,5,5
        }
    }
    return 0;
}
int main(){
    int arr[100] = {7,9,11,23};
    int size=4, element=45, capacity=100, index=3;
    display(arr,size);
    //Reg_Insertion(arr, size, element, capacity, index);
    //size++;
    //display(arr,size);
    Deletion(arr, size, 2);
    size--;
    display(arr,size);

    return 0;
}