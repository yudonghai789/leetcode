#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * 对数组进行循环，计算每个元素开始，大于S需要的个数
 * 
 */
int minSubArrayLen(int s, int* nums, int numsSize){
    int result = numsSize + 1;
    int tempResult = 0;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int j = i;
        while ((sum < s) && (j < numsSize)) {
            sum = sum + nums[j];
            j++;
        }  
        if(sum >= s) {
            tempResult = j - i;
            result = (result > tempResult)? tempResult: result;
        }
    }
    
    result = (result > numsSize)? 0: result;
    return result;
}

int main()
{
	int result = 0;

    // int nums[6] = {2,3,1,2,4,3};
    // int numsSize = sizeof(nums) / sizeof(int);
    // int s = 7;

    int nums[6] = {1,2,3,4,5};
    int numsSize = sizeof(nums) / sizeof(int);
    int s = 11;

	result = minSubArrayLen(s, nums, numsSize);
	printf("%d", result);

    system("pause");
    return 0;
}