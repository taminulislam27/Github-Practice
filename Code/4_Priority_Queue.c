#include <stdio.h>
#define SIZE 5

int pqueue[SIZE];
int rear = -1;

/* Insert according to priority */
void enqueue(int val)
{
    if (rear == SIZE - 1)
    {
        printf("Priority Queue is Full\n");
        return;
    }

    int i;
    if (rear == -1)
    {
        pqueue[++rear] = val;
    }
    else
    {
        /* shift elements to maintain priority order */
        for (i = rear; i >= 0 && pqueue[i] < val; i--)
        {
            pqueue[i + 1] = pqueue[i];
        }
        pqueue[i + 1] = val;
        rear++;
    }
}

/* Remove highest priority element */
void dequeue()
{
    if (rear == -1)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("%d removed\n", pqueue[0]);

    for (int i = 0; i < rear; i++)
        pqueue[i] = pqueue[i + 1];

    rear--;
}

/* Display queue */
void display()
{
    if (rear == -1)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i <= rear; i++)
        printf("%d ", pqueue[i]);
    printf("\n");
}

int main()
{
    display();
    enqueue(10);
    enqueue(30);
    enqueue(20);
    enqueue(50);
    enqueue(40);
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
