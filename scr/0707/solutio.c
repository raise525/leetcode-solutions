#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct MyLinkedListNode {
    int val;
    struct MyLinkedListNode* next;
} MyLinkedListNode;

// 定义链表结构体
typedef struct {
    MyLinkedListNode* dummyHead;  // 虚拟头节点
    int size;                     // 链表长度
} MyLinkedList;

/** 创建并初始化链表 */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->dummyHead = (MyLinkedListNode*)malloc(sizeof(MyLinkedListNode));
    obj->dummyHead->val = 0;      // 虚拟头节点的值不重要
    obj->dummyHead->next = NULL;  // 初始为空链表
    obj->size = 0;                // 初始长度为0
    return obj;
}

/** 获取链表中第 index 个节点的值。如果索引无效，则返回 -1 */
int myLinkedListGet(MyLinkedList* obj, int index) {
    // 检查索引是否有效
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    
    MyLinkedListNode* current = obj->dummyHead->next;  // 从真实头节点开始
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->val;
}

/** 在链表头部添加一个节点 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    // 创建新节点
    MyLinkedListNode* newNode = (MyLinkedListNode*)malloc(sizeof(MyLinkedListNode));
    newNode->val = val;
    
    // 新节点指向原来的第一个节点
    newNode->next = obj->dummyHead->next;
    // 虚拟头节点指向新节点
    obj->dummyHead->next = newNode;
    
    obj->size++;  // 链表长度增加
}

/** 在链表尾部添加一个节点 */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    // 创建新节点
    MyLinkedListNode* newNode = (MyLinkedListNode*)malloc(sizeof(MyLinkedListNode));
    newNode->val = val;
    newNode->next = NULL;  // 尾部节点的next为NULL
    
    // 找到最后一个节点
    MyLinkedListNode* current = obj->dummyHead;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // 最后一个节点指向新节点
    current->next = newNode;
    
    obj->size++;  // 链表长度增加
}

/** 在链表第 index 个节点前插入一个节点 */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    // 如果index大于链表长度，不插入
    if (index < 0 || index > obj->size) {
        return;
    }
    
    // 创建新节点
    MyLinkedListNode* newNode = (MyLinkedListNode*)malloc(sizeof(MyLinkedListNode));
    newNode->val = val;
    
    // 找到第index个节点的前一个节点
    MyLinkedListNode* current = obj->dummyHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    // 插入新节点
    newNode->next = current->next;
    current->next = newNode;
    
    obj->size++;  // 链表长度增加
}

/** 删除链表第 index 个节点 */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // 检查索引是否有效
    if (index < 0 || index >= obj->size) {
        return;
    }
    
    // 找到第index个节点的前一个节点
    MyLinkedListNode* current = obj->dummyHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    // 要删除的节点
    MyLinkedListNode* toDelete = current->next;
    // 跳过要删除的节点
    current->next = toDelete->next;
    
    // 释放内存
    free(toDelete);
    
    obj->size--;  // 链表长度减少
}

/** 释放链表内存 */
void myLinkedListFree(MyLinkedList* obj) {
    // 释放所有节点
    MyLinkedListNode* current = obj->dummyHead;
    while (current != NULL) {
        MyLinkedListNode* temp = current;
        current = current->next;
        free(temp);
    }
    // 释放链表结构体
    free(obj);
}

/** 打印链表（用于测试） */
void myLinkedListPrint(MyLinkedList* obj) {
    printf("链表内容: ");
    MyLinkedListNode* current = obj->dummyHead->next;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    printf("链表长度: %d\n", obj->size);
}

/** 测试函数 */
int main() {
    // 创建链表
    MyLinkedList* list = myLinkedListCreate();
    printf("1. 创建空链表\n");
    myLinkedListPrint(list);
    
    // 测试头部插入
    printf("\n2. 头部插入 1, 2, 3\n");
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtHead(list, 2);
    myLinkedListAddAtHead(list, 3);
    myLinkedListPrint(list);
    
    // 测试获取
    printf("\n3. 获取下标为1的元素: %d\n", myLinkedListGet(list, 1));
    
    // 测试尾部插入
    printf("\n4. 尾部插入 4, 5\n");
    myLinkedListAddAtTail(list, 4);
    myLinkedListAddAtTail(list, 5);
    myLinkedListPrint(list);
    
    // 测试中间插入
    printf("\n5. 在下标2处插入 99\n");
    myLinkedListAddAtIndex(list, 2, 99);
    myLinkedListPrint(list);
    
    // 测试删除
    printf("\n6. 删除下标为2的元素\n");
    myLinkedListDeleteAtIndex(list, 2);
    myLinkedListPrint(list);
    
    // 测试边界情况
    printf("\n7. 获取无效下标(-1): %d\n", myLinkedListGet(list, -1));
    printf("   获取无效下标(10): %d\n", myLinkedListGet(list, 10));
    
    // 清理内存
    myLinkedListFree(list);
    
    return 0;
}


