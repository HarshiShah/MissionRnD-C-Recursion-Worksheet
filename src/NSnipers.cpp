/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
void unmark(int *battlefield, int n, int row, int column);
void mark(int *battlefield, int n, int row, int column);
int place_nsnipers(int *battlefield, int n, int row_num);

int solve_nsnipers(int *battlefield, int n){
	if (n == 1){
		*battlefield = 1;
		return 1;
	}
	if (n <= 3)
		return 0;
	*(battlefield) = -1;
	int res = place_nsnipers(battlefield, n, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		if (*(battlefield + (n*i + j)) < 0)
			*(battlefield + (n*i + j)) = 0;
	}
	return res;
}

int place_nsnipers(int *battlefield, int n, int row_num){
	if (row_num == n)
		return 1;
	int index = 0;
	while (index < n){
		if (*(battlefield + (n*row_num + index)) == 0){
			mark(battlefield, n, row_num, index);
			if (place_nsnipers(battlefield, n, row_num + 1) == 0)
				unmark(battlefield, n, row_num, index);
			else{

				*(battlefield + (n*row_num + index)) = 1;
				break;
			}
		}
		index++;
	}
	if (index == n)
		return 0;
	else
		return 1;
}

void mark(int *battlefield, int n, int row, int column){
	int i, j;
	for (i = column + 1; i < n; i++)
		*(battlefield + (n*row + i)) = *(battlefield + (n*row + i)) - 1;
	for (i = column - 1; i >= 0; i--)
		*(battlefield + (n*row + i)) = *(battlefield + (n*row + i)) - 1;

	for (i = row + 1; i < n; i++)
		*(battlefield + (n*i + column)) = *(battlefield + (n*i + column)) - 1;
	for (i = row + 1, j = column + 1; i < n &&j < n; i++, j++)
		*(battlefield + (n*i + j)) = *(battlefield + (n*i + j)) - 1;
	for (i = row + 1, j = column - 1; i <n &&j >= 0; i++, j--)
		*(battlefield + (n*i + j)) = *(battlefield + (n*i + j)) - 1;
}

void unmark(int *battlefield, int n, int row, int column){
	int i, j;
	for (i = column + 1; i < n; i++)
		*(battlefield + (n*row + i)) = *(battlefield + (n*row + i)) + 1;
	for (i = column - 1; i >= 0; i--)
		*(battlefield + (n*row + i)) = *(battlefield + (n*row + i)) + 1;
	for (i = row + 1; i < n; i++)
		*(battlefield + (n*i + column)) = *(battlefield + (n*i + column)) + 1;
	for (i = row + 1, j = column + 1; i < n &&j < n; i++, j++)
		*(battlefield + (n*i + j)) = *(battlefield + (n*i + j)) + 1;
	for (i = row + 1, j = column - 1; i <n && j >= 0; i++, j--)
		*(battlefield + (n*i + j)) = *(battlefield + (n*i + j)) + 1;
}
