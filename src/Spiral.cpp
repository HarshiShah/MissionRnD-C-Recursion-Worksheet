/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include <stdlib.h>

void spiral_array(int **input_array, int* res, int length, int row_start, int col_start, int row_end, int col_end, int x, int y, int columns,int index);

int *spiral(int rows, int columns, int **input_array)
{
	if (rows<1 || columns<1 || input_array == NULL)
		return NULL;
	int* res = (int*)malloc(sizeof(int)*(rows*columns));
	spiral_array(input_array, res, rows*columns, 0, -1, rows, columns - 1, 0, 0, columns,0);
	return res;

}

void spiral_array(int **input_array, int* res, int length, int row_start, int col_start, int row_end, int col_end, int x, int y, int columns,int index){
	if (index == length)
		return;
	res[index] = input_array[x][y];
	if (x == row_start && y < col_end){
		if (y == col_start + 1)
			row_end--;
		y++;
	}
	else if (y == col_end &&x < row_end){
		if (x == row_start)
			col_start++;
		x++;
	}
	else if (x == row_end && y > col_start){
		if (y == col_end)
			row_start++;
		y--;
	}
	else if (y == col_start &&x > row_start){
		if (x == row_end)
			col_end--;
		x--;
	}
	index++;
	spiral_array(input_array, res, length, row_start, col_start, row_end, col_end, x, y, columns,index);
	return;
}
