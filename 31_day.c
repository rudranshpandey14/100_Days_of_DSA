#include <stdio.h>

#define MAX 100   // Maximum size of stack

int stack[MAX];
int top = -1;     // Initially stack is empty

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int choice, value;
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        }
    }

    return 0;
}
