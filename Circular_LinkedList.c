#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * head){
    struct Node * ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * insert_at_first(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head->next;
    ptr->data = data;

    while(p->next!=head){
        p = p->next;
    }
    //p points to last node
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;
    second -> data = 11;
    second -> next = third;
    third -> data = 16;
    third -> next = fourth;
    fourth -> data = 24;
    fourth -> next = head;
    head = insert_at_first(head, 80);
    traversal(head);

    return 0;

}