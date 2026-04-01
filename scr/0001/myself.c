#include <stdio.h>

//建立哈希表的结构体
struct HashTable
{
    int key; //数组的值
    int val; //数组的下标
    //句柄 
};

//这里应该还要初始化表为零

//哈希表查找
struct  HashTable* find(int key){
    struct HashTable* temp;
    temp =   ;//内部查找函数
    return temp;
} 

//哈希表插入
struct HashTable* insert(int key, int val){
    //怎么插
    struct HashTable* temp;
    temp->key = key;
    temp->val = val; //怎么要连起来吗？这个结构体怎么用？
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int a ;
    struct HashTable* temp;
    for (int i = 0; i < numsSize; i++){
        a = target - nums[i];
        temp=find(a);
        if(temp == NULL){
            //没找到就把nums[i]插入
            insert(nums[i], i);
        }
        else
        {
            return i,temp->val;
        }
    }

    //遍历完成之后，没找到，返回null
    return NULL;
}
