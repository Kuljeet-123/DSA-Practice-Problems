/*Modular Multiplicative Inverse
Given two integers ‘a’ and ‘m’. The task is to find modular multiplicative inverse of ‘a’ under modulo ‘m’.
Note: Print the smallest modular multiplicative inverse.

Input:
First line consists of T test cases. Only line of every test case consists of 2 integers 'a' and 'm'.

Output:
For each testcase, in a new line, print the modular multiplicative inverse if exists else print -1.

Your Task:
This is a function problem. You just need to complete the function modInverse() that takes a and m as parameters and returns modular multiplicative inverse of ‘a’ under modulo ‘m’.

Constraints:
1 <= T <= 100
1 <= m <= 100

Example:
Input:
2
3 11
10 17
Output:
4
12

Explanation:
Testcase 1:
Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not valid.
Testcase 2:
Input:  a = 10, m = 17
Output: 12
Since (12*10) mod 17 = 1, 12 is the modulo inverse of 10.
*/

// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
int modInverse(int a, int m)
{
    //Your code here
    a=a%m;
    for(int i=1;i<m;i++)
    {   if((a*i)%m==1)
         return i;
    }
    return -1;
    
}

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,m;
		cin>>a>>m;
		cout << modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends