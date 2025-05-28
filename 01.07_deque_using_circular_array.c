//Implementation of Deque (Double Ended Queue) using circular array

#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1,rear = -1;

//Function prototypes
void insertFront(int value);
void insertRear(int value);
int deleteFront();
int deleteRear();
int getFront();
int getRear();
int isFull();
int isEmpty();
void display();

//Main
int main(){
    int choice,value,result;
    int flag = 1;

    while(flag){
        printf("\n--Deque Menu--\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Get Front Element\n");
        printf("6. Get Rear Element\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to be inserted at front: ");
                scanf("%d",&value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to be inserted at rear: ");
                scanf("%d",&value);
                insertRear(value);
                break;
            case 3:
                result = deleteFront();
                if(result != 0) printf("Deleted from front: %d\n",result);
                break;
            case 4:
                result = deleteRear();
                if(result != 0)printf("Deleted from rear: %d\n",result);
                break;
            case 5:
                result = getFront();
                if(result != 0) printf("Front element: %d\n", result);
                break;
            case 6:
                result = getRear();
                if(result != 0) printf("Rear element: %d\n", result);
                break;
            case 7:
                display();
                break;
            case 8:
                flag = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try Again\n");

        }
    }

    return 0;
}

//Function definitions
int isFull(){
    return front == (rear + 1) % SIZE;
    //other logic
    // return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty(){
    return front == -1;
}

void insertFront(int value){
    if(isFull()){
        printf("Deque is full\n");
        return;
    }
    if(isEmpty()){
        front = rear = 0;
    }else{
        front = (front - 1 + SIZE) % SIZE;
    }
    //other logic instead of line 100
    //else if(front == 0){
    //  front = SIZE -1
    //}else{
    //  --front;
    //} 
    
    deque[front] = value;
    printf("Inserted at front: %d\n",value);
}

void insertRear(int value){
    if(isFull()){
        printf("Deque is Full\n");
        return;
    }
    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear + 1) % SIZE;
    }
    //other logic instead of line 121
    //else if(rear == SIZE -1){
    //  rear = 0;
    //} else {
    //  ++rear;
    //}
    deque[rear] = value;
    printf("Inserted at Rear: %d\n",value);
}

int deleteFront(){
    if(isEmpty()){
        printf("Deque is Empty\n");
        return 0;
    }
    int value = deque[front];
    if(front == rear){
        front = rear = -1; //only one element
    }else{
        front = (front + 1) % SIZE;
    }
    //other logic instead of line 136
    //else if(front == SIZE -1 ){
    //  front = 0;
    //}else{
    //  ++front;
    //}

    return value;
}

int deleteRear(){
    if(isEmpty()){
        printf("Deque is empty\n");
        return 0;
    }

    int value = deque[rear];
    if(front == rear){
        front = rear = -1;

    }else{
        rear = (rear - 1 + SIZE) % SIZE;
    }
    //other logic instead of line 159
    //else if(rear == 0){
    //  rear = SIZE -1;
    //}else{
    //  --rear;
    //}
    return value;
}

int getFront(){
    if(isEmpty()){
        printf("Dequeue is empty\n");
        return 0;
    }
    return deque[front];
}

int getRear(){
    if(isEmpty()){
        printf("Deque is empty\n");
        return 0;
    }
    return deque[rear];
}

void display(){
    if(isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");
    int i = front;
    while(1){
        printf("%d ",deque[i]);
        if(i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}