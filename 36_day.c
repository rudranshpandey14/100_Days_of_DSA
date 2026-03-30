#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % SIZE;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}
