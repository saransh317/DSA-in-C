#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if((ptr->top)==-1){return 1;}
    else{return 0;}
}

int isFull(struct stack * ptr){
    if((ptr->size)==(ptr->top+1)){return 1;}
    else{return 0;}
}

void push(struct stack * ptr, int val){
    if(isFull(ptr)==1){printf("Stack Overflow");}
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int peek(struct stack * sp, int i){
    if((sp->top-i+1)<0){printf("Invalid i");}
    else{
        return sp->arr[sp->top-i+1];
    }
}

void pop(struct stack* ptr){
    if(isEmpty(ptr)){printf("Stack Underflow");}
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
    }
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp,56);
    push(sp,7);
    push(sp,6);
    //printf("%d", isFull(sp));
    int i=1;
    printf("Value at %d position %d", i, peek(sp,i));


    return 0;
}

