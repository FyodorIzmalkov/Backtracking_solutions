/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knight_tour_problem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:49:29 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/14 16:28:51 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Knight tour problem solution

#include <stdio.h>
#include <stdbool.h>
# define N 8

int	solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

/* A utility function to check if i,j are valid indexes
   for N*N chessboard */
bool	isSafe(int x, int y, int sol[N][N])
{
	return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N] */

void printSolution(int sol[N][N])
{
	int i = 0;
	int j;
	while (i < N)
	{
		j = 0;
		while( j < N)
		{
			printf(" %2d ", sol[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/* This function solves the Knight Tour problem using
   Backtracking.  This function mainly uses solveKTUtil()
   to solve the problem. It returns false if no complete
   tour is possible, otherwise return true and prints the
   tour.
   Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.  */

bool	solveKT(void)
{
	int sol[N][N];

	/* Initialization of solution matrix */

	int x = -1;
	int y;
	while (++x < N)
	{
		y = -1;
		while(++y < N)
			sol[x][y] = -1;
	}

	/* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */

	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	// Since the Knight is initially at the first block
    sol[0][0]  = 0;

	/* Start from 0,0 and explore all tours using
       solveKTUtil() */

	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
	{
		printf("solution does not exist");
		return (false);
	}
	else
		printSolution(sol);
	return (true);
}

/* A recursive utility function to solve Knight Tour
   problem */

int	solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N])
{
	int k;
	int next_x;
	int next_y;

	if (movei == N*N)
		return (true);

	/* Try all next moves from the current coordinate x, y */

	k = -1;
	while (++k < 8)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == true)
				return (true);
			else
				sol[next_x][next_y] = -1; //backtracking
		}
	}
	return (false);
}

/* Driver program to test above functions */
int main(void)
{
	solveKT();
	return (0);
}
