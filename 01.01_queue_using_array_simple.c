//Implementation of queue using array (simple) (not efficient,not used in practical sense)

#include <stdio.h>
#define SIZE 100

//define array
int queue[SIZE];
int front = -1,rear = -1;

//Function prototypes

void enqueue(int value);
int dequeue();
void getFront();
void display();
int isEmpty();
int isFull();


//Main
int main()
{
    int choice, value;
    int flag = 1;
    int deleted;

    while(flag)
    {
        printf("\nQueue Menu--\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue\n");
        printf("3. Get Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to be queued: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                deleted = dequeue();
                if(deleted != 0)
                {
                    printf("Deleted: %d\n",deleted);
                }
                break;

            case 3:
                getFront();
                break;

            case 4:
                display();
                break;
            
            case 5:
                printf("Exiting Program.\n");
                flag = 0;
                break;

            default:
                printf("Invalid choice! Try Again.\n");
        }
    }

    return 0;
}

//Declaring the functions

int isFull()
{
    return rear == SIZE - 1;
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(int value)
{
    if(isFull())
    {
        printf("Queue is full!\n");
    }else {
        if(front == -1) front = 0; //when first element is inserted
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n",value);
    }
}

int dequeue()
{
    if(isEmpty()){
        printf("Queue is Empty!\n");
        return 0;
    }else{
        int value = queue[front];
        front++;
        return value;
    }
}

void getFront()
{
    if(isEmpty()){
        printf("Queue is empty!\n");

    }else{
        printf("Front Element is %d\n",queue[front]);
    }
}

void display(){
    if(isEmpty())
    {
        printf("Queue is empty!\n");
    }else{
        printf("Queue Element: ");
        int i;
        for(i = front;i<=rear;++i)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}