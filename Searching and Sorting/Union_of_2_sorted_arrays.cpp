/*Union of Two Sorted Arrays
Given two sorted arrays arr[] and brr[] of size N and M respectively. The task is to find the union of these two arrays.
Union of two arrays can be defined as the common and distinct elements in the two arrays.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of testcases T. For each testcase, first line of input contains size of two arrays N and M. Next two line contains N and M elements.

Output:
For each testcase, print the union (common and distinct) of two arrays in a single line. You need to print the union in sorted order.

Your Task:
This is a function problem. You only need to complete the function findUnion() that takes N and M as parameter and prints the union of two arrays. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N, M <= 105
1 <= arr[i], brr[i] <= 106

Example:
Input:
3
5 3
1 2 3 4 5
1 2 3
5 5
2 2 3 4 5
1 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2
Output:
1 2 3 4 5
1 2 3 4 5
1 2

Explanation:
Testcase 1: Distinct elements including both the arrays are: 1 2 3 4 5.
Testcase 2: Distinct elements including both the arrays are: 1 2 3 4 5.
Testcase 3: Distinct elements including both the arrays are: 1 2.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
void findUnion(int arr1[], int arr2[], int n, int m)
{
   //Your code here
   	 vector<int>v;
	 vector<int>u;
    for(int i=0;i<n;i++)
    {
    	if(arr1[i]!=arr1[i+1])
        v.push_back(arr1[i]);
    }
    for(int j=0;j<m;j++)
    {
    	if(arr2[j]!=arr2[j+1])
        v.push_back(arr2[j]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
    	if(v[i]!=v[i+1])
    	u.push_back(v[i]);
    }
     for(int i=0;i<u.size();i++)
    {
    	cout<<u[i]<<" ";
    } 
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    findUnion(arr1,arr2, N, M);
	    
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends