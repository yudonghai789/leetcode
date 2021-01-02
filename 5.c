#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 判断字符串是否为回文
 * 1、暴力求解
 * 思路：双层遍历输入字符串，从而穷举出输入字符串的所有子串，然后再用一层循环，判断子串是否为回文字符串，思路清晰简单，代码略。
 * 1. 中心扩散算法
 * 思路：遍历输入的字符串s，以每个字符mid为中心，分别计算mid为中心的奇数位（例如"cabac"中以"b"为中心的回文字符串）和偶数位（例如"cabbac"以"bb"为中心的回文字符串）的最长回文字符串，记录最长回文字符串出现的起始下标及长度max。
 * 2. 动态规划
 * 3. manacher 算法
 */



/**
 * 中心扩散算法
 * 从每一个书开始作为中心,获取最长的回文子串长度
 */
char *longestPalindrome(char *s){
    int len = strlen(s);
    int start = 0;
    int mid = 0;
    int max = 0;
    int extend = 0;
    for (mid = 0; mid < len; mid++) {
         while(mid - extend >= 0 && mid + extend + 1 < len && s[mid - extend] == s[mid + extend + 1]){
            extend++;
        }
        if(2 * extend >= max){
            max = 2 * extend;
            start = mid - extend + 1;
        }
        //计算形如 "cabac"中以"b"为中心的回文字符串
        extend = 0;
        while(mid - extend - 1 >= 0 && mid + extend + 1 < len && s[mid - extend - 1] == s[mid + extend + 1]){
            extend++;
        }
        if(2 * extend + 1 >= max){
            max = 2 * extend + 1;
            start = mid - extend;
        }
    }

    char *result = (char *)malloc((max + 1) * sizeof(char));
    for(int i = 0;i < max; i++){
        result[i] = s[start + i];
    }
    result[max] = '\0';
    
    return result;
}

int main()
{
	char* result = NULL;

    char *s= "babad";

	result = longestPalindrome(s);
	printf("%s", result);

    system("pause");
    free(result);
    return 0;
}
