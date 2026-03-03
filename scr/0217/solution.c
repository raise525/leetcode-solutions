#include <uthash.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义哈希表的节点结构
struct hashTable {
    int key;                // 存储数组元素的值
    UT_hash_handle hh;      // uthash库需要的句柄，让这个结构体支持哈希操作
};

bool containsDuplicate(int* nums, int numsSize) {
    // 创建一个空的哈希表指针，初始为NULL
    struct hashTable* set = NULL;
    
    // 遍历整个数组
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;  // 临时指针，用于存储查找结果
        
        // 在哈希表中查找当前元素 nums[i]
        // 参数说明：set-哈希表, nums+i-要查找的值的地址, tmp-查找结果
        // nums+i 等价于 &nums[i]，即当前元素的地址
        HASH_FIND_INT(set, nums + i, tmp);
        
        if (tmp == NULL) {  // 如果没找到（说明这个元素第一次出现）
            // 创建新的哈希表节点
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];  // 设置节点的key为当前元素值
            
            // 将新节点添加到哈希表中
            // 参数说明：set-哈希表, key-节点中key字段的名称, tmp-要添加的节点
            HASH_ADD_INT(set, key, tmp);
        } else {  
            // 如果找到了（说明这个元素之前已经出现过）
            // 直接返回true，表示存在重复元素
            return true;
        }
    }
    
    // 遍历完整个数组都没找到重复元素，返回false
    return false;
}