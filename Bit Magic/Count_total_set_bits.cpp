/*
Count total set bits
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is N.

Output:
For each testcase, in a new line, print the total count of all bits.

User Task:
The task is to complete the function countSetBits() that takes n as parameter and returns the count of all bits.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103

Example:
Input:
2
4
17
Output:
5
35

Explanation:
Testcase1:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0 set bits
0 0 1 = 1 set bits
0 1 0 = 1 set bits
0 1 1 = 2 set bits
1 0 0 = 1 set bits
Therefore, the total number of set bits is 5.
Testcase 2: From numbers 1 to 17(both inclusive), the total number of set bits is 35.
*/

#include<iostream>
using namespace std;

// Function to count set bits in the given number x
// n: input to count the number of set bits
int countSetBits(int N){
    
    // Your logic here
    int two = 2,count = 0; 
    int n = N; 
    while(n)
    { 
        count += (N/two)*(two>>1); 
        if((N & (two-1)) > (two >> 1)-1)
           count += (N & (two-1)) - (two >> 1)+1; 
        two <<= 1; 
        n >>= 1; 
    } 
    return count; 
}

int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}