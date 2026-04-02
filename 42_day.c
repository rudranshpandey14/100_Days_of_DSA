#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Stack structure
int stack[MAX];
int top = -1;

// Queue functions
void enqueue(int x) {
    if(rear == MAX-1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear)
        return -1;

    return queue[front++];
}

// Stack functions
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isQueueEmpty() {
    return front > rear;
}

int main() {
    int n, x;

    scanf("%d", &n);

    // input queue
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue -> stack
    while(!isQueueEmpty()) {
        push(dequeue());
    }

    // move stack -> queue
    while(top != -1) {
        enqueue(pop());
    }

    // print reversed queue
    while(!isQueueEmpty()) {
        printf("%d ", dequeue());
    }

    return 0;
}
