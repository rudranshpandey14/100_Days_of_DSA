#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

// push_front
void push_front(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = front;

    if(front == NULL){
        front = rear = newnode;
    }
    else{
        front->prev = newnode;
        front = newnode;
    }

    count++;
}

// push_back
void push_back(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = rear;

    if(rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }

    count++;
}

// pop_front
void pop_front(){
    if(front == NULL){
        printf("Deque Underflow\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if(front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

// pop_back
void pop_back(){
    if(rear == NULL){
        printf("Deque Underflow\n");
        return;
    }

    struct node* temp = rear;
    rear = rear->prev;

    if(rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

// front element
int getFront(){
    if(front == NULL){
        printf("Deque is empty\n");
        return -1;
    }
    return front->data;
}

// rear element
int getBack(){
    if(rear == NULL){
        printf("Deque is empty\n");
        return -1;
    }
    return rear->data;
}

// empty
int empty(){
    return (front == NULL);
}

// size
int size(){
    return count;
}

// display
void display(){
    struct node* temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    printf("Deque elements: ");
    display();

    printf("Front element: %d\n", getFront());
    printf("Back element: %d\n", getBack());

    pop_front();
    pop_back();

    printf("Deque after deletion: ");
    display();

    printf("Size: %d\n", size());

    if(empty())
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");

    return 0;
}
