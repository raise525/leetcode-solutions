#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义单链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 反转链表 (迭代法)
 * @param head 原链表的头节点
 * @return 反转后链表的新头节点
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next; // 暂存下一个节点
        curr->next = prev;                       // 将当前节点指向前一个节点，实现反转
        prev = curr;                              // 移动prev指针到当前节点
        curr = nextTemp;                           // 移动curr指针到下一个节点
    }
    return prev; // prev最终指向原链表的尾节点，即新链表的头节点
}

/**
 * 使用快慢指针找到链表前半部分的尾节点
 * 若链表有奇数个节点，中间的节点归为前半部分
 * @param head 链表的头节点
 * @return 前半部分链表的尾节点
 */
struct ListNode* endOfFirstHalf(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    // 快指针每次走两步，慢指针每次走一步
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow; // 当快指针走到末尾时，慢指针恰好在前半部分的尾节点
}

/**
 * 判断链表是否为回文链表
 * 算法步骤：
 * 1. 找到前半部分的尾节点
 * 2. 反转后半部分链表
 * 3. 比较前后两半是否相等
 * 4. 恢复链表原状（可选，但推荐以保持函数无副作用）
 * @param head 链表的头节点
 * @return 如果是回文链表返回true，否则返回false
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true; // 空链表视为回文
    }

    // 1. 找到前半部分链表的尾节点
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    // 2. 反转后半部分链表
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    // 3. 判断是否回文
    struct ListNode* p1 = head;          // 指向前半部分开头
    struct ListNode* p2 = secondHalfStart; // 指向反转后的后半部分开头
    bool result = true;
    while (result && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false; // 发现值不相等，不是回文
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4. 恢复链表原状 (将后半部分再次反转并接回)
    firstHalfEnd->next = reverseList(secondHalfStart);

    return result;
}

/**
 * 辅助函数：根据数组创建链表 (用于测试)
 * @param arr 包含节点值的整型数组
 * @param size 数组的大小
 * @return 新创建链表的头节点
 */
struct ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head;
}

/**
 * 辅助函数：打印链表 (用于测试)
 * @param head 链表的头节点
 */
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("链表内容: ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

/**
 * 辅助函数：释放链表占用的内存 (用于测试)
 * @param head 链表的头节点
 */
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * 主函数：包含测试用例
 */
int main() {
    // 测试用例1: 回文链表 [1,2,2,1]
    int arr1[] = {1, 2, 2, 1};
    struct ListNode* list1 = createLinkedList(arr1, 4);
    printf("测试用例1:\n");
    printLinkedList(list1);
    bool result1 = isPalindrome(list1);
    printf("是否为回文链表: %s\n\n", result1 ? "true" : "false");
    freeLinkedList(list1);

    // 测试用例2: 非回文链表 [1,2]
    int arr2[] = {1, 2};
    struct ListNode* list2 = createLinkedList(arr2, 2);
    printf("测试用例2:\n");
    printLinkedList(list2);
    bool result2 = isPalindrome(list2);
    printf("是否为回文链表: %s\n\n", result2 ? "true" : "false");
    freeLinkedList(list2);

    // 测试用例3: 单个节点链表 [1] (回文)
    int arr3[] = {1};
    struct ListNode* list3 = createLinkedList(arr3, 1);
    printf("测试用例3:\n");
    printLinkedList(list3);
    bool result3 = isPalindrome(list3);
    printf("是否为回文链表: %s\n\n", result3 ? "true" : "false");
    freeLinkedList(list3);

    // 测试用例4: 空链表 (视为回文)
    printf("测试用例4: 空链表\n");
    bool result4 = isPalindrome(NULL);
    printf("是否为回文链表: %s\n", result4 ? "true" : "false");

    return 0;
}