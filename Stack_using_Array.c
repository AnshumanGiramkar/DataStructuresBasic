#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 90
int stack[SIZE];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==SIZE-1;
}
void push(){
    int data;
    if(isFull()){
        printf("Stack is Full...\n");
        return;
    }
    else{
    int per=1;
    while(per==1){
    printf("Enter A Number=\n");
    scanf("%d",&data);
    top++;
    stack[top]=data;
    printf("Do you want to continue? 1-yes, other than 1-no:");
    scanf("%d",&per);
    }
}
}
void pop(){
    if(isEmpty()){
        printf("Stack is Empty...\n");
        return;
    }
    else{
        int permis=1;
        while(permis==1){
        int popped;
        popped=stack[top];
        printf("Popped Element=%d\n",popped);
        printf("Do you want to continue? 1-yes, other than 1-no:");
        scanf("%d",&permis);
        top--;
        }
    }
}
void peak(){
    if(isEmpty()){
        printf("Stack is Empty...\n");
        return;
    }
    else{
        printf("At top=%d\n",stack[top]);
    }
}
int main(){
    push();
    pop();
    peak();
}
