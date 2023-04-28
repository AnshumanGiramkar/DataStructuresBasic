#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct Stack{
    Node* top;
}Stack;
int isEmpty(Stack* stack){
    return stack->top==NULL;
}
Stack* createStack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}
void push(Stack* stack, int data){
    Node* newNode=(Node*)malloc(sizeof(newNode));
    newNode->data=data;
    newNode->next=stack->top;
    stack->top=newNode;
}
int pop(Stack* stack){
    int item;
    if(isEmpty(stack)){
        printf("Empty Stack...\n");
        return -1;
    }
    else{
        Node* temp=stack->top;
        item=temp->data;
        stack->top=stack->top->next;
        free(temp);
    }
    return item;
}
int peek(Stack* stack){
    int item;
    if(isEmpty(stack)){
        printf("Empty Stack...\n");
        return -1;
    }
    else{
        item=stack->top->data;
    }
    return item;
}
void display(Stack* stack){
    if(isEmpty(stack)){
        printf("Empty Stack...\n");
    }
    else{
    Node* current=stack->top;
    printf("Stack Values:\t");
    while(current->next!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("\n");
    }
}
int main(){
    Stack* st=createStack();
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    push(st,6);
    push(st,7);
    push(st,8);
    push(st,9);
    display(st);
    printf("Peak Value=%d\n",peek(st));
    printf("Popped Value=%d\n",pop(st));
    display(st);
    printf("Popped Value=%d\n",pop(st));
    display(st);
    return 0;
}
