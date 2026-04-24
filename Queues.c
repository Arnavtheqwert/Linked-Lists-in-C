#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));

    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    struct Node* temp = front;
    front = temp->next;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void displayqueue(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    do{
        printf("*** Please enter what operation to carry out-: ***\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit.\n");

        scanf("%d", &choice);

        switch(choice){
            case 1: 
                printf("Please enter data to enqueue into queue: \n");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayqueue();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Error.\n");
        }
    }while(choice!=4);
    return 0;
}