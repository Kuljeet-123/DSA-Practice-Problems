/*Transpose of Matrix
Write a program to find transpose of a square matrix mat[][] of size N*N. Transpose of a matrix is obtained by changing rows to columns and columns to rows.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case contains an integer N, denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix.

Output:
For each test case output will be the space separated values of the transpose of the matrix

User Task:
The task is to complete the function transpose() which finds the transpose of the matrix. The printing is done by the driver code.

Constraints:
1 <= T <= 15
1 <= N <= 20
-103 <= mat[i][j] <= 103

Example:
Input:
2
4
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4
2
1 2 -9 -2
Output:
1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4
1 -9 2 -2

Explanation:
Testcase 1: The matrix after rotation will be: 1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4.
Testcase 2: The matrix after rotation will be: 1 -9 2 -2.
*/

#include <bits/stdc++.h> 
using namespace std; 

#define N 30


/*  Function which converts A[][] to its transpose
*   n: size of matrix
*   N: globally defined for matrix
*   A: input matrix
*/
void transpose( int A[][N],int n) 
{ 
	// Your code here
	for(int i = 0; i < n; i++)
	{
	    for(int j = i + 1; j < n; j++)
	        swap(A[i][j],A[j][i]);
	}
}

int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int A[N][N];
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            cin >> A[i][j];
	        }
	    }
	    
	    transpose(A, n);
	    
	    for (int i = 0; i < n; i++) 
    	{ 
    		for (int j = 0; j < n; j++) 
    		printf("%d ", A[i][j]); 
    	
    	}
    	cout<<endl;
	    
	}

	return 0; 
} 