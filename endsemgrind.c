#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*head, *temp, *current;

void traverseList(struct Node* head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void searchList(struct Node* head, int value){
    struct Node* temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->data == value){
            printf("%d found in linked list as position %d", value, count+1);
            break;
        }
        else{
            temp = temp->next;
            count++;
        }
    }
}


int main(){
    head = NULL;

    for(int i = 0; i<10; i++){
        temp = (struct Node*)(malloc(sizeof(struct Node)));
        temp->data = i;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = temp;
        }
    }
    traverseList(head);
    searchList(head, 6);
    return 0;
}