#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 20
typedef struct queue
{
    int *data;
    int head;
    int rear;
    int size;
} Queue;

typedef struct
{
    Queue *queue1, *queue2;
} MyStack;

Queue *initQueue(int k)
{
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->data = (int *)malloc(k * sizeof(int));
    obj->head = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

void enQueue(Queue *obj, int e)
{
    if (obj->head == -1)
    {
        obj->head = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = e;
}

int deQueue(Queue *obj)
{
    int a = obj->data[obj->head];
    if (obj->head == obj->rear)
    {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isEmpty(Queue *obj)
{
    return obj->head == -1;
}

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

void myStackPush(MyStack *obj, int x)
{
    enQueue(obj->queue2, x);

    while (!isEmpty(obj->queue1))
    {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }

    Queue *temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
}

int myStackPop(MyStack *obj)
{
    if (isEmpty(obj->queue1))
    {
        return -1;
    }

    return deQueue(obj->queue1);
}

int myStackTop(MyStack *obj)
{
    if (isEmpty(obj->queue1))
    {
        return -1;
    }
    return obj->queue1->data[obj->queue1->head];
}

bool myStackEmpty(MyStack *obj)
{
    return isEmpty(obj->queue1);
}

void myStackFree(MyStack *obj)
{
    free(obj->queue1->data);
    free(obj->queue1);
    free(obj->queue2->data);
    free(obj->queue2);
    free(obj);
}
