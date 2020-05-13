/*
Given an array of distinct elements of size N, find the number of pairs in the array with their sum greater than 0.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which will contain N. Second line contains N space separated integers. 

Output:
Print number of valid pairs whose sum is greater that 0.

Your Task:
Complete the function ValidPair() that takes array and N as input and returns an integer.

Constraints: 
1 <= T <= 100
1 <= N <= 104
-104 <= A[i] <= 104

Example:
Sample Input:
2
3
3 -2 1
4
-1 -1 -1 0

Sample Output:
2
0

Explanation:
Testcase 1 : There are two pairs of elements in the array whose sum is positive. They are:
{3, -2} = 1
{3, 1} = 4

*/

#include <bits/stdc++.h> 
using namespace std; 
int ValidPair(int* array, int n) ;

//User function Template for C++

int ValidPair(int* arr, int n) 
{ 
    // code here 
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=0)
           continue;
           
       int j = lower_bound(arr,arr+n,-arr[i] + 1) -  arr;
       ans += i-j;
    }
    return ans;
} 

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
		cout<<ValidPair(array,n)<<endl;
	}
	return 0; 
} 
