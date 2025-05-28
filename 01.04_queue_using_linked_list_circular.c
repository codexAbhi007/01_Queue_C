//Implementation of circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

//Function prototypes
void enqueue(int value);
int dequeue();
void display();
void getFront();
int isEmpty();

//Main

int main()
{
  int choice,value,deleted,flag = 1;
  
  while(flag)
  {
     printf("\nCircular Queue (Linked List) Menu--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to be queued: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                deleted = dequeue();
                if(deleted != 0)
                    printf("Dequeued: %d\n", deleted);
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
                printf("Invalid Choice! Try Again\n");
        }
    }

    return 0;
}

//Function definitions

int isEmpty()
{
    return (front == NULL);
}

void enqueue(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory Allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty())
    {
        front = rear = newNode;
        rear->next = front;
    }else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Enqueued: %d\n",value);
}

int dequeue(){
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return 0;
    }

    int value;
    if(front == rear){
        //only one node
        value = front->data;
        free(front);
        front = rear = NULL;
    }else{
        struct Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    return value;
}

void getFront(){
    if(isEmpty()){
        printf("Queue is empty!\n");
    }else{
        printf("Front Element: %d\n",front->data);
    }
}


void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");

    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != front);
    printf("\n");
}