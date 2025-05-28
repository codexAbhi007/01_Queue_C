//Implementation of queue using 2 stacks (dequeue costly)
// enqueue - O(1)
// dequeue - O(n)

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

//Function prototypes
void push1(int val);
int pop1();
void push2(int val);
int pop2();
int isEmpty1();
int isEmpty2();

void enqueue(int val);
int dequeue();
void display();

//Main 
int main(){
    int choice,value,deleted,flag = 1;

    while(flag) {
        printf("\nQueue Using Stacks (Dequeue Costly)\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                deleted = dequeue();
                if(deleted != 0)
                    printf("Dequeued: %d\n", deleted);
                break;
            case 3:
                display();
                break;
            case 4:
                flag = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

//Stack operations
void push1(int val)
{
    if(top1 == SIZE -1){
        printf("Stack 1 Overflow\n");
        return;
    }
    stack1[++top1] = val;
}

int pop1(){
    if(top1 == -1)
    {
        printf("Stack 1 Underflow\n");
        return 0;
    }
    return stack1[top1--];
}

void push2(int val){
    if(top2 == SIZE -1){
        printf("Stack 2 Overflow\n");
        return;
    }
    stack2[++top2] = val;
}

int pop2(){
    if(top2 == -1)
    {
        printf("Stack 2 Underflow\n");
        return 0;
    }
    return stack2[top2--];
}

int isEmpty1(){
    return top1 == -1;
}

int isEmpty2(){
    return top2 == -1;
}

//Queue Operations
void enqueue(int val){
    push1(val);
    printf("Enqueued: %d\n",val);
}

int dequeue(){
    if(isEmpty1() && isEmpty2()){
        printf("Queue is empty\n");
        return 0;
    }

    if(isEmpty2()){
        while(!isEmpty1()){
            push2(pop1());
        }
    }

    return pop2();
}

void display(){
    if(isEmpty1() && isEmpty2()){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i;
    for(i = top2;i>=0;--i){
        printf("%d ",stack2[i]);
    }
    for(i = 0;i<=top1;++i){
        printf("%d ",stack1[i]);
    }

    printf("\n");
}