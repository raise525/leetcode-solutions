#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct StackNode
{
    int data;
    struct StackNode* next;
}StackNode;

typedef struct Stack
{
    StackNode* top;
    int size;
}Stack;

typedef struct 
{
    Stack* A;
    Stack* B;
}MyQueue;

Stack* stackCreate(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stackPush(Stack* stack, int x){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = x;
    newNode->next = stack->top;   //用头插法模拟栈的先入后出
    stack->top = newNode;
    stack->size++;
}

int stackPop(Stack* stack){
    if(!stack->top) return -1;
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int stackTop(Stack* stack){
    if(!stack->top) return -1;
    return stack->top->data;
}

bool stackEmpty(Stack* stack){
    return stack->top == NULL;
}

void stackFree(Stack* stack){
    while(!stackEmpty(stack)){
        stackPop(stack);
    }
    free(stack);
}

MyQueue* myQueueCreate(){
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->A = stackCreate();
    queue->B = stackCreate();
    return queue;
}

void myQueuePush(MyQueue* obj, int x){
    stackPush(obj->A, x);
}

int myQueuePeek(MyQueue* obj);  //函数声明

int myQueuePop(MyQueue* obj){
    int peek = myQueuePeek(obj);
    if(peek != -1){
        stackPop(obj->B);
    }
    return peek;
}

int myQueuePeek(MyQueue* obj){
    if(!stackEmpty(obj->B)){
        return stackTop(obj->B);
    }

    if(stackEmpty(obj->A)){
        return -1;
    }

    while(!stackEmpty(obj->A)){
        int x = stackTop(obj->A);
        stackPop(obj->A);
        stackPush(obj->B, x);
    }
    return stackTop(obj->B);
}

bool myQueueEmpty(MyQueue* obj){
    return stackEmpty(obj->A) && stackEmpty(obj->B);
}

void myQueueFree(MyQueue* obj){
    if(obj){
        stackFree(obj->A);
        stackFree(obj->B);
        free(obj);
    }
}


