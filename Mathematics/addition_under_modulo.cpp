/* 
Addition Under Modulo
You are given two numbers a and b. You need to find the sum of a and b under modulo M.
Note: Take M as 109+7

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing a and b.

Output:
For each testcase, in a new line, print sum of a and b under modulo M.

Your Task:
This is a function problem. You need to complete the function sumUnderModulo that takes a and b as parameters and returns sum of a and b under modulo M.

Constraints:
1 <= T <= 100
1 <= a,b <= 263-1

Examples:
Input:
2
9223372036854775807 9223372036854775807
1000000007 1000000007
Output:
582344006
0

Explanation:
Testcase 1: 9223372036854775807 + 9223372036854775807  = 18446744073709551614. Now do (18446744073709551614) mod (109+7) = 582344006
Testcase 2: 1000000007 + 1000000007  = ‭(2000000014‬)mod(109+7) = 0

*/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++


int sumUnderModulo(long long a,long long b)
{
    int M=1000000007;
    //your code here
    long long  sum=a%M+b%M;
    sum=sum%M;
    
  return sum;
}

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    cout<<sumUnderModulo(a,b)<<endl;
	}
	return 0;
}  // } Driver Code Ends