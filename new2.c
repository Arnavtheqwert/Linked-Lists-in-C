#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty(){
    return (top == NULL);
}

void push(int value){
    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));

    if(newNode == NULL){
        printf("Error.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;

    top = newNode;

}

int pop(){
    if(top == NULL){
        printf("Error. Underflow detected.\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);

    return value;
}

int peek(){
    if(isEmpty()){
        printf("Error. Stack empty.\n");
        return -1;
    }
    return top->data;
}

void display(){
    struct Node* temp = top;

    if(isEmpty()){
        printf("Stack empty.\n");
        return;
    }

    while(temp != NULL){
        printf("%d\n", temp->data);
        printf("\n");
        printf("|\n");
        printf("v\n");
        printf("\n");
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, value;
    do{
        printf("*** Please enter an operation to perform: ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter a value to push into stack: \n");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("%d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting application...\n");
             break;
            default:
                printf("Error.\n");
                return 0;
        }
    }while(choice != 5);
}