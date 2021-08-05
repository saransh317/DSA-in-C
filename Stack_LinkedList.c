#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top){
    if(top==NULL){return 1;}
    return 0;
}

int isFull(struct Node * top){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){return 1;}
    return 0;
}

int pop(struct Node ** top){
    if(isEmpty(*top)){printf("Stack Underflow");}
    else{
        struct Node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }    
}

struct Node* push(struct Node * top, int val){
    if(isFull(top)){printf("Stack Overflow\n");}
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = val;
        n->next = top;
        top = n;
        return top;}
}

int peek(struct Node * top, int pos){
    struct Node * ptr = top;
    for(int i=0;(i<(pos -1) && ptr!=NULL);i++){
        ptr = ptr->next;
    }

    if(ptr!=NULL){return ptr->data;}
    else{return -1;}
}

int stackTop(struct Node * top){return top->data;}
int stackBottom(struct Node * top){
    struct Node * ptr = top;
    while(ptr->next!=NULL){ptr=ptr->next;}
    return ptr->data;
}

void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("\nElement: %d", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node * top = NULL;//(struct Node *)malloc(sizeof(struct Node));
    top = push(top,78);
    top = push(top,71);
    top = push(top,7);
    //traversal(top);
    //printf("\n");
    //printf("%d",pop(&top));
    printf("%d",peek(top,2));
    traversal(top);
    printf("\n Stack Tops is %d", stackTop(top));
    printf("\n Stack Bottom is %d", stackBottom(top));
    return 0;
}