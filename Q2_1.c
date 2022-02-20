#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#define N 10

struct stack{
    int data;
    struct node *next;
}*top;
int size = 0;

void push(int item);
int pop();
void display();

int main(){
    int choice,data;
    while(1){
        printf("1. for push\n  2. for pop\n 3. for display\n 4. for exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    printf("\nEnter data to push into:");
                    scanf("%d",&data);
                    push(data);
                    break;
            case 2:
                    data = pop();
                    if(data != INT_MIN)
                        printf("\nData => %d\n",data);
                    break; 
            case 3:
                   display();                
                   break; 
            case 4:
                    exit(1);
                    break;
            default:
                    printf("Enter correct choice");                             
        }
    }
    return 0;    
}

void push(int item){
    if( size <= N){
        printf("\nstack is full");
        return;
    }
    struct stack *newnode =(struct stack*)malloc(sizeof(struct stack));
    newnode->data = item;
    newnode->next = top;
    top = newnode;
    size++;
    printf("data pushed to stack.\n");
}

int pop(){
    int data = 0;
    struct stack * topnode;
    if(size <=0 || !top){
        printf("stack is empty\n");
        return INT_MIN;
    }
    topnode = top;
    data = top->next;
    free(topnode);
    size--;
    return data;
}

void display(){
    struct stack * temp=top;
    if(top==0){
        printf("empty stack\n");
    }
    else{
        while(temp!=0){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }

}