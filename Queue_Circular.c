#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int * arr;
    int f; int r;
};

int isFull(struct Queue * q){
    if(((q->r)+1)%(q->size) == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue * q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * q, int val){
    if(isFull(q)){printf("\nQueue Overflow!");}
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("\nElement Enqueued = %d", val);
    }
}

int dequeue(struct Queue * q){
    int a=-1;
    if(isEmpty(q)){printf("Queue Underflow");}
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        return a;
    }
}

void traversal(struct Queue * q){
    int i=0;
    for(i=q->f+1;i<q->r+1;i++){
        printf("\nNumber %d: %d", i+1, q->arr[i]);
    }
}

int main(){
    struct Queue q;
    q.size=4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    if(isEmpty(&q)){printf("\nQueue is Empty.");}
    //dequeue(&q);

    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 81);
    printf("\nDequeuing Element: %d", dequeue(&q));
    enqueue(&q, 81);
    
    return 0;
}