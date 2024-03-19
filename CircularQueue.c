#include <stdio.h>
#define size 5
int front = -1;
int rear = -1;
int queue[size];

void enqueue()
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }
    else if (rear == -1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    
    printf("Enter the number: ");
    scanf("%d", &queue[rear]);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d deleted\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d deleted\n", queue[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);

    return 0;
}
