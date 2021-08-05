#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insert_at_first(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

struct Node * insert_at_index(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;

    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr -> data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insert_at_end(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node * insert_after(struct Node* head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;  
}

struct Node * delete_first(struct Node * head){
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node * delete_between(struct Node * head, int index){
    struct Node * p = head;
    int i=0;
    while(i<index-1){
        p = p->next;
        i++;
    }
    struct Node * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * delete_end(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * delete_find_value(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
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
    fourth -> next = NULL;

    //head = insert_at_first(head, 97);
    //head = insert_at_index(head, 56, 2);
    //head = insert_at_end(head, 56);
    //head = insert_after(head, second, 56);
    //head = delete_between(head, 2);
    //head = delete_end(head);
    //head = delete_first(head);
    head = delete_find_value(head, 16);
    traversal(head);

    
    return 0;
}