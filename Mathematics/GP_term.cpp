/*GP Term
Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.

Input:
First line contains an integer, the number of test cases 'T'. T testcases follow. Each test case in its first line contains two positive integer A and B (First 2 terms of GP). In the second line of every test case it contains of an integer N.

Output:
In each seperate line print the Nth term of the Geometric Progression. Print the floor ( floor(2.3)=2 ) of the answer.

Your Task:
This is a function problem. You need to complete the function termOfGP() that takes A and B as parameter and returns Nth term of GP. The return value should be double that would be automatically converted to floor by the driver code.

Constraints:
1 <= T <= 100
-100 <= A <= 100
-100 <= B <= 100
1 <= N <= 5

Example:
Input:
2
2 3
1
1 2
2
Output:
2
2

Explanation:
Testcase 1: Since we need to find the 1st element, we know it is 2 as first element is 2 and second is 3.
Testcase 2: The second term of series whose common ratio is 2 will be 2.
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
double termOfGP(int A,int B,int N)
{
    //Your code here
    double r=((double)B)/A;
  return floor(A*(pow(r,N-1)));    
}

// { Driver Code Starts.


int main()
{
    int T; //testcases total
    cin>>T;//input the testcases

    for(int i=0;i<T;i++) //white testcases are not exhausted
    {
        int A,B;
        cin>>A>>B; //input first and second term of gp
        int N;
        cin>>N; //input n
        
        cout<<floor(termOfGP(A,B,N))<<endl;
    }

    return 0;
}

  // } Driver Code Ends