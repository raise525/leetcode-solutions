#include "uthash.h" // 引入 uthash 库头文件
#include <stdlib.h> // 引入标准库头文件，包含 malloc 和 free 函数
#include <stdio.h> // 引入标准输入输出库头文件，包含 printf 函数

struct  hashTable
{
    int key;
    int value;
    UT_hash_handle hh; // 哈希表句柄，必须包含
};

struct hashTable * hashtable = NULL;

struct hashTable * find(int ikey)
{
    struct hashTable * tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey,int ival)
{
    struct hashTable * it = find(ikey);
    if(it == NULL)
    {
        struct hashTable * tmp = malloc(sizeof(struct hashTable ));  //动态分配一个 struct hashTable 类型所需大小的内存空间，并将这块内存的起始地址赋值给指针变量 tmp。
        if(tmp == NULL)
        {
            return;
        }
        tmp->key = ikey;
        tmp->value = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    }else{
        it->value = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hashtable = NULL;
    for(int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        struct hashTable* it = find(complement);
        if(it != NULL)
        {
            int * ret = malloc(sizeof(int) * 2);
            ret[0] = it->value;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i],i);
    }
    *returnSize = 0;
    return NULL;
}