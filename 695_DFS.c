#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEARCHFALG 5

void printGrid(int** grid, int gridSize, int* gridColSize)
{
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < (*gridColSize); j++) {
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	printf("------------------------\n");
}

int dfs(int **grid, int i, int j, int row, int col)
{
	if (i < 0 || i > row - 1 || j < 0 || j > col - 1 || grid[i][j] == 0 || grid[i][j] == SEARCHFALG) {
		return 0;
	}
	grid[i][j] = SEARCHFALG;
	return 1 + dfs(grid, i + 1, j, row, col) + dfs(grid, i - 1, j, row, col) + dfs(grid, i, j + 1, row, col) + dfs(grid, i, j - 1, row, col);
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
	int result = 0;
	int temp = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < (*gridColSize); j++) {
			if (grid[i][j] == 1) {
				temp = dfs(grid, i, j, gridSize, *gridColSize);
				result = (result > temp)? result: temp;
				printGrid(grid, gridSize, gridColSize);
			}
		}
	}
	
	return result;
}

int main() 
{
	int result;
	
	int gradCharData[8][13] = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	int row = 8;
	int cloum = 13;
	
	int *gradRowPointer[row];
    for (int i = 0; i < row; i++) {
		gradRowPointer[i] = &gradCharData[i][0];
	}

	result = maxAreaOfIsland(gradRowPointer, row, &cloum);

	printf("%d", result);

	system("pause");
	return 0;
}
