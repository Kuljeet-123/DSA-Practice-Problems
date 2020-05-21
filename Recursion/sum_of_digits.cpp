/*
Sum of Digits of a Number
You are given a number n. You need to find the sum of digits of n.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing n.

Output:
For each testcase, in a newline, print the sum of digits of n.

Your Task:
This is a function problem. You only need to complete the function sumOfDigits that takes n as parameter and returns the sum of digits of n.

Constraints:
1 <= T <= 105
1 <= n <= 107

Examples:
Input:
2
1
99999
Output:
1
45

Explanation:
Testcase 1: Sum of digits for 1 is 1.
Testcase 2: Sum of digits for 99999 is 9 + 9 + 9 + 9 + 9 = 45 
*/

#include <iostream>
using namespace std;

// Complete this function
int sumOfDigits(int n)
{
    //Your code here
    if(n<10)
      return n;

  return sumOfDigits(n/10)+n%10;

}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<sumOfDigits(n)<<endl;
	    
	    
	}
	return 0;
}