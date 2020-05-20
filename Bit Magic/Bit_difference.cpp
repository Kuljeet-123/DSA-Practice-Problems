/*
Bit Difference
You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is A and B separated by a space.

Output:
For each testcase, in a new line, print the number of bits needed to be flipped.

User Task:
The task is to complete the function countBitsFlip() that takes A and B as parameters and returns the count of the number of bits to be flipped to convert A to B.

Constraints:
1 ≤ T ≤ 100
1 ≤ A, B ≤ 103

Example:
Input:
2
10 20
20 25
Output:
4
3

Explanation:
Testcase 1:
A  = 01010
B  = 10100
As we can see, the bits of A that need to be flipped are 01010. If we flip these bits, we get 10100, which is equal to B.
Testcase 2:
A  = 10100
B  = 11001
As we can see, the bits of A that need to be flipped are 10100. If we flip these bits, we get 11001, which is equal to B.
*/


#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) 
{ 
    int count = 0; 
    while (n > 0) 
    { 
        count++; 
        n &= (n-1); 
    } 
    return count; 
} 

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    
    // Your logic here
    return countSetBits(a^b); 
}

int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}