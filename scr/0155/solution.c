#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 
 * 定义链表节点结构体
 * 每个节点代表栈中的一个元素
 */
typedef struct MinStackNode {
    int val;                    // 存储节点的实际值
    int min;                    // 存储"从栈底到该节点"的所有值中的最小值
    struct MinStackNode* next;  // 指向下一个节点的指针（链表结构）
} MinStackNode;

/* 
 * 定义最小栈结构体
 * 这是栈的管理器，只维护栈顶指针，这里是使用的是头插法，模拟栈的先入后出，每次pop都是top出去！！
 */
typedef struct {
    MinStackNode* top;          // 栈顶指针，指向最新的节点
} MinStack;

/* 
 * 创建并初始化一个最小栈
 * 返回值: 指向新创建的最小栈的指针
 */
MinStack* minStackCreate() {
    // 分配内存给MinStack结构体
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    
    // 初始化栈顶指针为NULL，表示空栈
    obj->top = NULL;
    
    // 返回创建好的栈
    return obj;
}

/* 
 * 向栈中压入一个元素
 * 参数:
 *   obj - 指向最小栈的指针
 *   val - 要压入的值
 */
void minStackPush(MinStack* obj, int val) {
    // 1. 为新节点分配内存
    MinStackNode* newNode = (MinStackNode*)malloc(sizeof(MinStackNode));
    
    // 2. 设置新节点的值
    newNode->val = val;
    
    // 3. 计算新节点的min值（核心逻辑）
    if (obj->top == NULL) {
        // 情况1：栈为空，这是第一个节点
        // 最小值就是它自己
        newNode->min = val;
    } else {
        // 情况2：栈不为空
        // 获取当前栈顶节点的min值（即到当前节点的最小值）
        int currentMin = obj->top->min;
        
        // 比较新值和当前最小值，取更小的作为新节点的min值
        // 这样每个节点都记录了"从栈底到该节点"的最小值
        newNode->min = (val < currentMin) ? val : currentMin;
    }
    
    // 4. 将新节点插入到链表头部（栈的特性：后进先出）
    // 新节点的next指向原来的栈顶
    newNode->next = obj->top;
    
    // 5. 更新栈顶指针，使其指向新节点
    obj->top = newNode;
    
    // 至此，新节点已成为栈顶，并且它的min字段记录了正确的全局最小值
}

/* 
 * 从栈中弹出栈顶元素
 * 参数:
 *   obj - 指向最小栈的指针
 */
void minStackPop(MinStack* obj) {
    // 1. 检查栈是否为空
    if (obj->top == NULL) {
        // 栈为空，直接返回，不做任何操作
        return;
    }
    
    // 2. 保存当前栈顶节点，用于稍后释放内存
    MinStackNode* temp = obj->top;
    
    // 3. 将栈顶指针移动到下一个节点（新的栈顶）
    // 注意：这里不需要更新min值，因为每个节点已经存储了正确的最小值
    obj->top = obj->top->next;
    
    // 4. 释放原栈顶节点的内存
    free(temp);
}

/* 
 * 获取栈顶元素的值（不弹出）
 * 参数:
 *   obj - 指向最小栈的指针
 * 返回值: 栈顶元素的值，如果栈为空则返回INT_MAX
 */
int minStackTop(MinStack* obj) {
    // 1. 检查栈是否为空
    if (obj->top != NULL) {
        // 栈不为空，返回栈顶节点的val字段
        return obj->top->val;
    }
    
    // 2. 栈为空，返回INT_MAX作为错误指示
    return INT_MAX;
}

/* 
 * 获取栈中的最小值
 * 参数:
 *   obj - 指向最小栈的指针
 * 返回值: 当前栈中的最小值，如果栈为空则返回INT_MAX
 * 时间复杂度: O(1) - 直接读取栈顶节点的min字段
 */
int minStackGetMin(MinStack* obj) {
    // 1. 检查栈是否为空
    if (obj->top != NULL) {
        // 栈不为空，返回栈顶节点的min字段
        // 因为栈顶节点的min字段记录了从栈底到栈顶的所有值的最小值
        return obj->top->min;
    }
    
    // 2. 栈为空，返回INT_MAX作为错误指示
    return INT_MAX;
}

/* 
 * 释放整个栈占用的内存
 * 参数:
 *   obj - 指向最小栈的指针
 */
void minStackFree(MinStack* obj) {
    // 1. 循环弹出所有节点，释放每个节点的内存
    // 使用minStackPop函数，因为它会同时处理链表连接和内存释放
    while (obj->top != NULL) {
        minStackPop(obj);
    }
    
    // 2. 释放MinStack结构体本身的内存
    free(obj);
}

/* 
 * 示例：演示如何使用最小栈
 */
int main() {
    printf("=== 最小栈使用示例 ===\n");
    
    // 1. 创建最小栈
    MinStack* stack = minStackCreate();
    printf("1. 栈创建成功\n");
    
    // 2. 压入元素
    printf("\n2. 压入元素 -2\n");
    minStackPush(stack, -2);
    printf("   当前栈: [-2]\n");
    printf("   当前最小值: %d\n", minStackGetMin(stack));
    
    printf("\n3. 压入元素 0\n");
    minStackPush(stack, 0);
    printf("   当前栈: [0, -2]（栈顶在前）\n");
    printf("   当前最小值: %d\n", minStackGetMin(stack));
    
    printf("\n4. 压入元素 -3\n");
    minStackPush(stack, -3);
    printf("   当前栈: [-3, 0, -2]\n");
    printf("   当前最小值: %d\n", minStackGetMin(stack));
    
    // 3. 获取栈顶元素
    printf("\n5. 查看栈顶元素\n");
    printf("   栈顶元素: %d\n", minStackTop(stack));
    
    // 4. 弹出元素
    printf("\n6. 弹出栈顶元素\n");
    minStackPop(stack);
    printf("   弹出后栈: [0, -2]\n");
    printf("   当前最小值: %d\n", minStackGetMin(stack));
    printf("   栈顶元素: %d\n", minStackTop(stack));
    
    // 5. 继续操作
    printf("\n7. 压入元素 -5\n");
    minStackPush(stack, -5);
    printf("   当前栈: [-5, 0, -2]\n");
    printf("   当前最小值: %d\n", minStackGetMin(stack));
    
    // 6. 清理内存
    printf("\n8. 释放栈内存\n");
    minStackFree(stack);
    printf("   内存释放完成\n");
    
    return 0;
}




