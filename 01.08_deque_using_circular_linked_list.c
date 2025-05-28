//Implementation of Deque (Double Ended Queue) using singly circular linked list

#include <stdio.h>
#include <stdlib.h>

//Node Structure
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* front = NULL;
Node* rear = NULL;

//Function prototypes
void insertFront(int val);
void insertRear(int val);
int deleteFront();
int deleteRear();
int getFront();
int getRear();
void display();

//Main
int main(){
    int choice, value,result;
    int flag = 1;

    while(flag) {
        printf("\nDeque Menu (Using Linked List):\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                insertRear(value);
                break;
            case 3:
                result = deleteFront();
                if(result != 0)
                    printf("Deleted from front: %d\n", result);
                else  
                    printf("Deque is Empty\n");
                break;
            case 4:
                result = deleteRear();
                if(result != 0)
                    printf("Deleted from rear: %d\n",result);
                else    
                    printf("Deque is Empty\n");
                break;
            case 5:
                result = getFront();
                if(result != 0)
                    printf("Front Element: %d\n",result);
                else 
                    printf("Deque is Empty\n");
                break;
            case 6:
                result = getRear();
                if(result != 0)
                    printf("Rear Element: %d\n",result);
                else 
                    printf("Deque is Empty\n");
                break;
            case 7:
                display();
                break;
            case 8:
                flag = 0;
                printf("Exiting...");
                break;
            default:
                printf("Invalid Choice! Try Again");
                break;

        }
    }

    return 0;
}

//Function definitions
void insertFront(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    if(!newNode) return;

    if(front == NULL){
        newNode->next = newNode->prev = newNode;
        front = rear = newNode;
    }else{
        newNode->next = front;
        newNode->prev = rear;
        front->prev = newNode;
        rear->next = newNode;
        front = newNode;
    }
}

void insertRear(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    if(!newNode) return;

    if(rear == NULL){
        newNode->next = newNode->prev = newNode;
        front = rear = newNode;
    }else{
        newNode->prev = rear;
        newNode->next = front;
        rear->next = newNode;
        front->prev = newNode;
        rear = newNode;
    }
}

int deleteFront(){
    if(front == NULL)
        return 0;
    int val = front->data;

    if(front == rear){
        //only one element
        free(front);
        front=rear =NULL;
    }else{
        Node* temp = front;
        front = front->next;
        rear->next = front;
        front->prev = rear;
        free(temp);
    }
    return val;
}

int deleteRear(){
    if(rear == NULL)
        return 0;
    int val = rear->data;

    if(front == rear){
        free(rear);
        front = rear = NULL;
    }else{
        Node* temp = rear;
        rear = rear->prev;
        rear->next = front;
        front->prev = rear;
        free(temp);
    }
    return val;
}

int getFront(){
    if(front == NULL) return 0;
    return front->data;
}

int getRear(){
    if(rear == NULL) return 0;
    return rear->data;
}

void display(){
    if(front == NULL)
    {
        printf("Deque is empty\n");
        return;

    }
    Node* temp = front;
    printf("Deque: ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != front);
    printf("\n");
}