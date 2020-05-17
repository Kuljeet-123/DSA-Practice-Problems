/*
Spirally traversing a matrix
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Your Task:
This is a function problem. You only need to complete the function spirallyTraverse that takes m, n, and matrix as parameters and prints the spiral traversal. The driver code automatically appends a new line.

Constraints:
1 <= T <= 100
2 <= M, N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7
*/

#include <iostream>
using namespace std;

#define SIZE 30

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main() {
	int T = 0;
	
	scanf("%d",&T);
	
	while(T--)
	{
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;
	    
	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }
	    
	    spirallyTraverse(m, n, ar);
	    cout<<endl;
	   
	}
	return 0;
}
//Complete this function
void spirallyTraverse(int m, int n, int arr[SIZE][SIZE]){
    //Your code here
     int i, k = 0, l = 0; 
  
    while (k < m && l < n) { 
        for (i = l; i < n; ++i) { 
            cout << arr[k][i] << " "; 
        } 
        k++; 
        for (i = k; i < m; ++i) { 
            cout << arr[i][n - 1] << " "; 
        } 
        n--; 
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                cout << arr[m - 1][i] << " "; 
            } 
            m--; 
        } 
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                cout << arr[i][l] << " "; 
            } 
            l++; 
        } 
    } 
}
