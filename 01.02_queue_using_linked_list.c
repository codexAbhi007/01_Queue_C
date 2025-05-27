//Implementation of queue using linked list 

#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;


//Function prototypes
void enqueue(int value);
int dequeue();
int isEmpty();
void getFront();
void display();

//Main 
int main()
{
    int choice,value,flag = 1;
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
                    printf("Deleted: %d\n",deleted); 
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

//Function definitions

int isEmpty()
{
    return front == NULL;
}

void enqueue(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory Allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        //first element
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted: %d\n",value);
}

int dequeue()
{
    if(isEmpty()){
        printf("Queue is Empty!\n");
        return 0;
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return value;
}

void getFront()
{
    if(isEmpty()){
        printf("Queue is empty!\n");
    }else{
        printf("Front element: %d\n",front->data);
    }
}

void display(){
    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}