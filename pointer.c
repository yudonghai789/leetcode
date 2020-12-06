#include <stdio.h>
#include <string.h>


void func(char **str, int n, int m)
{
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\nstr[%d] = %s\n", i, str[i]);
        }
    }  
}

void main()
{
    char str[3][5] = {
        { 'a', 'b', 'c', 'b', 'c'},
        { 'a', 'b', 'c', 'b', 'c'},
        { 'a', 'b', 'c', 'b', 'c'}
    }

    func(str, 3, 5);
}