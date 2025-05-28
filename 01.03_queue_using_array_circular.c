//Implementation of circular queue using array 

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

//Function prototypes
void enqueue(int value);
int dequeue();
int isEmpty();
int isFull();
void getFront();
void display();

//Main

int main()
{
    int choice, value, flag = 1;
    int deleted;
    while(flag)
    {
        printf("\nCircular Queue Menu--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to be queued: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            
            case 2:
                deleted = dequeue();
                if(deleted != 0)
                    printf("Dequeued: %d\n",deleted);
                break;
            case 3:
                getFront();
                break;
            case 4:
                display();
                break;
            case 5:
                flag = 0;
                printf("Exiting Program.\n");
                break;
            default:
                printf("Invalid Choice! Try Again\n");
        }
    }

    return 0;
}

//Function Definitions

int isFull(){
    return (front == (rear+1)%SIZE);
}

int isEmpty(){
    return (front == -1);
}

void enqueue(int value){
    if(isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear+1)%SIZE;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n",value);
}

int dequeue(){
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return 0;
    }
    int value = queue[front];

    if(front == rear){
        //Only 1 element present
        front = rear = -1;
    }else{
        front = (front+1) % SIZE;
    }

    return value;
}

void getFront(){
    if(isEmpty()){
        printf("Queue is Empty\n");

    }else{
        printf("Front Element is %d\n",queue[front]);
    }
}

void display()
{
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }  

    printf("Queue: ");
    int i = front;
    while(1)
    {
        printf("%d ",queue[i]);
        if(i == rear)
            break;
        i = (i+1) % SIZE;
    }
    printf("\n");
}