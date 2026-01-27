#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

/* Check if queue is full */
int isFull()
{
    return (front == (rear + 1) % SIZE);
}

/* Check if queue is empty */
int isEmpty()
{
    return (front == -1);
}

/* Insert element */
void enqueue(int val)
{
    if (isFull())
    {
        printf("Circular Queue is Full\n");
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % SIZE;
    cq[rear] = val;
    printf("%d inserted\n", val);
}

/* Remove element */
void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("%d removed\n", cq[front]);

    if (front == rear)   // only one element
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

/* Display queue */
void display()
{
    if (isEmpty())
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    display();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
