#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct queue
{
    int *data;// 存储队列元素的数组
    int head;// 队头指针，指向队列的第一个元素
    int rear;// 队尾指针，指向队列的最后一个元素
    int size;
} Queue;

typedef struct
{
    Queue *queue1, *queue2;// 两个队列，queue1用于存储栈元素，queue2用于辅助操作
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
    obj->rear = (obj->rear + 1) % obj->size;// 更新队尾指针，使用循环数组的方式
    obj->data[obj->rear] = e;
}

int deQueue(Queue *obj)
{
    int a = obj->data[obj->head];// 获取队头元素
    if (obj->head == obj->rear)// 如果队列只有一个元素，重置队头和队尾指针
    {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;// 更新队头指针，使用循环数组的方式
    return a;
}

int isEmpty(Queue *obj)
{
    return obj->head == -1;// 判断队列是否为空
}

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(20);// 初始化queue1，设置大小为20
    obj->queue2 = initQueue(20);// 初始化queue2，设置大小为20
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
