/*
Determinant of a Matrix
Given a square matrix mat of size N x N. The task is to find the determinant of this matrix.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix. The next line contains the elements of the matrix in row-wise form.

Output:
Print the determinant of the matrix.

Your Task:
This is a function problem. You only need to complete the function determinantOfMatrix() that takes matrix and n as parameters and returns determinant.

Constraints:
1 <= T <= 40
1 <= N <= 7
-10 <= mat[i][j] <= 10

Example:
Input:
2
4
1 0 2 -1 3 0 0 5 2 1 4 -3 1 0 5 0
3
1 2 3 4 5 6 7 10 9
Output:
30
12

Explanation:
Testcase 1: Determinant of the given matrix is 30.
Testcase 2: Determinant of the given matrix is 12.
*/

#include <bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 100

void getcofactor(int arr[N][N], int temp[N][N],int p, int q, int n){
     int i = 0, j = 0;
     for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = arr[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/*  Function to find determinant of matrix
*   mat[][]: input matrix
*   n: given size of matrix
*   N: defined size globally
*/
int determinantOfMatrix( int mat[N][N], int n)
{
    
    // Your code here
     int D=0;
    if(n==1)
    {
        return mat[0][0];
    }
    int sign=1;
    int temp[N][N];    int i=0;
    for(i=0;i<n;i++)
    {
        getcofactor(mat,temp,0,i,n);
        D +=sign*mat[0][i]*determinantOfMatrix(temp,n-1);
        sign = -sign;
    }
    return D;
    
}

int main()
{
	  int t;
	cin>>t;
	while(t--)
	{
	  int no;
	cin>>no;
	  int mat[N][N];
	for(  int i=0;i<no;i++)
	{
	    for(  int j=0;j<no;j++)
	    {
	        cin>>mat[i][j];
	    }
	}
	printf("%d",determinantOfMatrix(mat, no));
	printf("\n");
	}
	return 0;
} 