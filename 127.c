#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_QUEUE_SIZE 100000

/* 判断两个节点是否相连 */
bool canChangeOneToEndword(char *a, char *b)
{
    int len = strlen(a); // 所有单词具有相同的长度, beginWord 和 endWord 是非空的
    int cnt = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
        if (cnt > 1) {
            return false;
        }
    }
    return true;
}

int ladderLength(char * beginWord, char * endWord, char **wordList, int wordListSize)
{
    char *queue[MAX_QUEUE_SIZE] = {0};
    int start = 0;
    int end = 0;
    int *flag = (int *)malloc(sizeof(int) * wordListSize);
    memset(flag, 0, sizeof(int) * wordListSize);
    int changenum = 1;

    queue[end++] = beginWord;
    while (start < end) {
        int curlevelnum = end - start; // 遍历当前变化次数相同的单词，查看当前的word变化情况，是否满足条件
        for (int i = 0; i < curlevelnum; i++) {
            char *tem = queue[start + i];
            if (strcmp(tem, endWord) == 0) {
                return changenum; // 广度优先搜索，出现该字符的变化一定是最小步骤变化而来，可以直接返回
            }

            for (int j = 0; j < wordListSize; j++) {
                // 当前word未访问过，同时tem和当前word能够通过一次字母变化变成相同的
                if (flag[j] == 0 && canChangeOneToEndword(tem, wordList[j]) == 1) {
                    queue[end++] = wordList[j];
                    flag[j] = 1;
                }
            }
        }
        start += curlevelnum;
        changenum++;
    }

    return 0;
}

int main()
{
	int result = 0;

    char *beginWord = "hit";
    char *endWord = "cog";
    char *wordList[] = {"hot","dot","dog","lot","log","cog"};
    int wordListSize = 6;
    // char *wordListPointer = (char *)malloc(sizeof(char) * wordListSize);
    // for (int i = 0; i < wordListSize; i++) {
	// 	wordListPointer[i] = &wordList[i];
	// }

	result = ladderLength(beginWord, endWord, wordList, wordListSize);
	printf("%d", result);

    system("pause");
    return 0;
}
