#include <stdio.h>
#include "uthash.h"
/**
 * 哈希表结构体定义
 * 使用uthash库实现的哈希表节点
 */
struct hashTable {
    int key;           // 键：存储数组元素的值
    int val;           // 值：存储数组元素的索引
    UT_hash_handle hh; // uthash库所需的内部句柄，必须命名为hh
};

// 全局哈希表指针，初始化为NULL
struct hashTable* hashtable = NULL;

/**
 * 在哈希表中查找指定键的元素
 * @param ikey 要查找的键值
 * @return 返回指向找到的哈希表节点的指针，如果未找到则返回NULL
 */
struct hashTable* find(int ikey) {
    struct hashTable* tmp; // 用于接收查找结果的指针
    
    // HASH_FIND_INT: uthash宏，用于在哈希表中查找整数键
    // 参数1: 哈希表头指针
    // 参数2: 要查找的键的指针
    // 参数3: 输出参数，指向找到的节点
    HASH_FIND_INT(hashtable, &ikey, tmp);
    
    return tmp;
}

/**
 * 向哈希表中插入或更新键值对
 * @param ikey 要插入的键
 * @param ival 要插入的值
 */
void insert(int ikey, int ival) {
    // 先查找键是否已存在
    struct hashTable* it = find(ikey);
    
    if (it == NULL) {
        // 键不存在，创建新节点
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        if (tmp == NULL) {
            return; // 内存分配失败
        }
        
        tmp->key = ikey; // 设置键
        tmp->val = ival; // 设置值
        
        // HASH_ADD_INT: uthash宏，向哈希表添加整数键
        // 参数1: 哈希表头指针
        // 参数2: 键字段的名称（必须是结构体的成员名）
        // 参数3: 要添加的节点指针
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        // 键已存在，更新对应的值
        it->val = ival;
    }
}

/**
 * 两数之和算法实现
 * 在数组中找到两个数，使它们的和等于目标值
 * @param nums 输入整数数组
 * @param numsSize 数组大小
 * @param target 目标值
 * @param returnSize 返回数组的大小（输出参数）
 * @return 包含两个索引的数组，如果没找到则返回NULL
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 初始化哈希表为空
    hashtable = NULL;
    
    // 遍历数组中的每个元素
    for (int i = 0; i < numsSize; i++) {
        // 计算需要查找的补数
        int complement = target - nums[i];
        
        // 在哈希表中查找补数是否存在
        struct hashTable* it = find(complement);
        
        if (it != NULL) {
            // 找到补数，说明当前元素和补数的和等于target
            // 分配返回数组的内存
            int* ret = malloc(sizeof(int) * 2);
            if (ret == NULL) {
                *returnSize = 0;
                return NULL;
            }
            
            // 设置返回结果
            // it->val 是补数的索引（之前插入的）
            // i 是当前元素的索引
            ret[0] = it->val; // 补数的索引
            ret[1] = i;       // 当前元素的索引
            
            *returnSize = 2; // 设置返回数组大小为2
            
            // 注意：这里没有释放哈希表内存，实际使用中可能需要
            // HASH_CLEAR(hh, hashtable);
            
            return ret;
        }
        
        // 没找到补数，将当前元素插入哈希表
        // key = nums[i] (数组元素的值)
        // val = i (当前元素的索引)
        insert(nums[i], i);
    }
    
    // 遍历完整个数组都没有找到符合条件的数对
    *returnSize = 0; // 设置返回大小为0
    return NULL;     // 返回NULL
}

/**
 * 算法思路总结：
 * 1. 使用哈希表存储数组元素值和对应的索引
 * 2. 遍历数组，对于每个元素 nums[i]：
 *    a. 计算 complement = target - nums[i]
 *    b. 在哈希表中查找 complement
 *    c. 如果找到，返回 [哈希表中complement的索引, i]
 *    d. 如果没找到，将当前元素插入哈希表
 * 
 * 时间复杂度：O(n)，只需要遍历一次数组
 * 空间复杂度：O(n)，最坏情况下需要存储所有元素
 * 
 * 示例：
 * 输入：nums = [2, 7, 11, 15], target = 9
 * 执行过程：
 * i=0: complement=7, 哈希表中没有7，插入 {2:0}
 * i=1: complement=2, 哈希表中找到2(索引0)，返回 [0, 1]
 */