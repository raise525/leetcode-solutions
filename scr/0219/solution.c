#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uthash.h>

struct HashEntry
{
    int key;
    int val;
    UT_hash_handle hh;
};

void hashAddItem( struct HashEntry**obj, int key,int val){
    struct HashEntry *pEntry;
    pEntry = malloc(sizeof(struct HashEntry));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
}

struct HashEntry *hashFindItem(const struct HashEntry **obj, int key){
    struct HashEntry *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

void hashFreeAll(struct HashEntry **obj){
    struct HashEntry *curr, *next;
    HASH_ITER(hh, *obj, curr, next){
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

bool cintainsNearbyDuplicate(int* nums, int numsSize, int k){
    struct HashEntry *dictionary = NULL;
    for(int i = 0;i <numsSize; i++){
        struct HashEntry *pEntry = hashFindItem(&dictionary, nums[i]);

        if(NULL != pEntry && i - pEntry->val <= k){
            hashFreeAll(&dictionary);
            return true;
        }

        //这里的思路是，找相同的，如果能找到并且间隔小于k，就是true，但是找到了，长度不符合就把原来哈希表里面的删掉，再加入当前的
        if(pEntry != NULL){
            HASH_DEL(dictionary, pEntry);
            free(pEntry);
        }
        hashAddItem(&dictionary, nums[i], i);

    }
    hashFreeAll(&dictionary);
    return false;
}
