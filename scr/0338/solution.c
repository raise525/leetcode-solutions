int* countBits(int num, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    for (int i = 0; i <= num; i++)
    {
        int count = 0;
        int n = i;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        result[i] = count;
    }
    return result;
}


int* countBits(int num, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    result[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        if(i % 2 == 0)
        {
            result[i] = result[i / 2];
        }
        else
        {
            result[i] = result[i - 1] + 1;
        }
        
    }
    return result;
}