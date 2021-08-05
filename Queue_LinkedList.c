#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * f = NULL;
struct Node * r = NULL;

void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));

    if(n==NULL){printf("\nQueue Full!");}
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){ f=r=n;}
        else{
            r->next = n;
            r = n;
        }
    }
}

int dequeue(){
    int val=-1;
    struct Node * ptr = f;
    if(f==NULL){printf("\nQueue is Empty");}
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}


int main(){
    enqueue(78);
    enqueue(7);
    enqueue(18);
    enqueue(71);
    traversal(f);
    dequeue(); dequeue();
    traversal(f);
    enqueue(12);
    printf("\n");
    traversal(f);
    return 0;

    
}