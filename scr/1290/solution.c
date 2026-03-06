#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 核心函数：将二进制链表转换为十进制
int getDecimalValue(struct ListNode* head) {
    int result = 0;
    
    while (head != NULL) {
        result = result * 2 + head->val;
        head = head->next;
    }
    
    return result;
}

// 辅助函数：创建新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：打印链表
void printList(struct ListNode* head) {
    printf("链表: ");
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 测试代码
int main() {
    // 创建链表: 1 -> 0 -> 1 -> 0 (二进制 1010 = 十进制 10)
    struct ListNode* head = createNode(1);
    head->next = createNode(0);
    head->next->next = createNode(1);
    head->next->next->next = createNode(0);
    
    // 打印链表
    printList(head);
    
    // 转换并输出结果
    int result = getDecimalValue(head);
    printf("转换结果: %d\n", result);
    
    // 更多测试用例
    struct ListNode* test2 = createNode(1);
    test2->next = createNode(1);
    test2->next->next = createNode(1);
    
    printList(test2);
    printf("转换结果: %d\n", getDecimalValue(test2));
    
    // 释放内存（实际使用时需要完整释放所有节点）
    // 这里简化处理
    free(head);
    free(test2);
    
    return 0;
}