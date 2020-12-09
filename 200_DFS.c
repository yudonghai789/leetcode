#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dfs(char **grid, int i, int j, int row, int col)
{
	if (i<0 || i >row - 1 || j<0 || j>col - 1 || grid[i][j] == '0') return;
	grid[i][j] = '0';
	dfs(grid, i + 1, j, row, col);
	dfs(grid, i - 1, j, row, col);
	dfs(grid, i, j + 1, row, col);
	dfs(grid, i, j - 1, row, col);
}


// gridSize是行数
// *gridColSize是列数 
int numIslands(char** grid, int gridSize, int* gridColSize) {
	int result = 0;
	for (int i = 0; i < (gridSize); i++) {
		for (int j = 0; j < (*gridColSize); j++) {
			if (grid[i][j] == '1') {
				dfs(grid, i, j, gridSize, *gridColSize);
				result++;
			}
		}
	}

	return result;
}

int main() 
{
	int result;
	
	char gradCharData[4][5] = {
		{'1','1','0','0','0'},
  		{'1','1','0','0','0'},
  		{'0','0','1','0','0'},
 		{'0','0','0','1','1'}
	};
	int row = 4;
	int cloum = 5;
	
	char *gradRowPointer[4];
    for (int i = 0; i < row; i++) {
		gradRowPointer[i] = &gradCharData[i][0];
	}

	result = numIslands(gradRowPointer, row, &cloum);
	// result = numIslands(&gradRowPointer[0], row, &cloum);  // 第一个参数也可以写成  &gradRowPointer[0]
	printf("%d", result);

	system("pause");
	return 0;
}