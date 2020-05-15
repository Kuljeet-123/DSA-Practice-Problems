/*Adding two matrices
Addition is one of the easiest operation to carry out. The same hold true for matrices. Two matrices can be added only if they have the same dimensions. The elements at similar positions get added.

You are given two matrices. The first matrix's dimensions are given by n1,m1. The second matrix's dimensions are given by n2,m2. You need to add both the matrices. If addition is not possible then print -1.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains four lines of input. The first line contains dimensions of the first array n1 and m1. The second line contains n1*m1 elements separated by spaces. The third line contains dimensions of the second array n2 and m2. The fourth line contains n2*m2 elements separated by spaces.

Output:
For each testcase, in a new line, print the sum of matrix if possible; else print -1.

Your Task:
This is a function problem. You only need to complete the function sumMatrix that taks n1, m1, n2, m2, matrix1, matrix2 as parameters and prints the sum of matrices. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= n1, m1, n2, m2 <= 30
0 <= arri <= 100

Examples:
Input:
2
2 3
1 2 3 4 5 6
2 3
1 3 3 2 3 3
3 2
1 2 3 4 5 6
3 2
1 3 3 2 3 3
Output:
2 5 6 6 8 9
2 5 6 6 8 9

Explanation:
Testcase 1: Adding each elements in first matrix to the elements with corresponding row and column (cell) of another matrix will result in the sum as 2 5 6 6 8 9.
Testcase 2: Adding each elements in first matrix to the elements with corresponding row and column of 2nd matrix , will result in the sum as 2 5 6 6 8 9.
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

/*  Function to find sum of matrices
*   n1, m1, n2, m2: rows and columns of matrices respectively
*   arr1[][], arr2[][]: two input matrices
*/
void sumMatrix(int n1, int m1, int n2, int m2, int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    
    // Your code here
    int sum[100][100];
    int i,j;
    if(n1==n2 && m1==m2)
    {
        for( i=0;i<n1;i++)
        {
            for( j=0;j<m1;j++)
            {
                sum[i][j]=arr1[i][j] + arr2[i][j];
            }
        }
        for( i=0;i<n1;i++)
        {
            for( j=0;j<m1;j++)
            {
                cout << sum[i][j] << " ";
            }
        }
        
    }
    
    else
    {
        cout << "-1";
    }
}


int main() {
    int t;
    cin>>t;//input the number of testcases
    
    while(t--) //while testcases exist
    {
        int n1,m1; //input rows and columns of matrix 1
        cin>>n1>>m1;
        int arr1[SIZE][SIZE]; //initialize the matrix 1 with n1 row and m1 columns.
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j]; //inputting the data in the matrix 1
        
        int n2,m2; //input rows and columns of matrix 2
        cin>>n2>>m2;
        int arr2[SIZE][SIZE];//initialize the matrix 2 with n2 row and m2 columns.
        for(int i=0;i<n2;i++)
        for(int j=0;j<m2;j++)
        cin>>arr2[i][j];//inputting the data in matrix 2
        
        sumMatrix(n1, m1, n2, m2, arr1, arr2);
        cout<<endl;
        
    }
    
	return 0;
} 