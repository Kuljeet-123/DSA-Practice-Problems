/*Square root
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(√x).

Input:
First line of input contains number of testcases T. For each testcase, the only line contains the number x.

Output:
For each testcase, print square root of given integer.

User Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Constraints:
1 ≤ T ≤ 1000
1 ≤ x ≤ 107

Example:
Input:
2
5
4
Output:
2
2

Explanation:
Testcase 1: Since, 5 is not perfect square, so floor of square_root of 5 is 2.
Testcase 2: Since, 4 is a perfect square, so its square root is 2.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);
  

 // } Driver Code Ends


// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    // Your code goes here 
    long long int i;
    for(i=1;i*i<=x;i++);
    return i-1;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends