#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char * arr;
};

int isEmpty(struct stack * ptr){
    if((ptr->top)==-1){return 1;}
    else{return 0;}
}

int isFull(struct stack * ptr){
    if((ptr->size)==(ptr->top+1)){return 1;}
    else{return 0;}
}

int stackTop(struct stack* sp){return sp->arr[sp->top];}

void push(struct stack * ptr, int val){
    if(isFull(ptr)==1){printf("Stack Overflow");}
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack* ptr){
    if(isEmpty(ptr)){printf("Stack Underflow");return -1;}
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch=='*' || ch=='/'){return 3;}
    else if(ch=='+' || ch=='-'){return 2;}
    else{return 0;}
}

int isOperator(char ch){
    if(ch=='+' || ch=='/' || ch=='*' || ch=='-'){return 1;}
    else{return 0;}
}

char * infix_to_postfix(char * infix){
    struct stack *sp;
    sp->size=45;
    sp->top=-1;
    sp->arr= (char *)malloc(sp->size*sizeof(char));

    char * postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));

    int i=0; //Track Infix
    int j=0; //Track Postfix

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++; j++;
        }
        else{
            if(precedence(infix[i])>stackTop(sp)){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char* exp = "a-b+t/6";
    printf("%s", infix_to_postfix(exp));    
    return 0;
}