/*
Power of 2
Given a positive integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

Input:
The first line contains T denoting the number of test cases. Each test case contains a single positive integer N.

Output:
Print "YES" if it is a power of 2 else "NO" (Without the double quotes).

User Task:
Your task is to complete the function isPowerofTwo() which takes n as parameter and returns true or false by checking is given number can be represented as power of two or not.

Constraints:
1 <= T <= 100
0 <= N <= 1018

Example:
Input :
2
1
98

Output :
YES
NO

Explanation:
Testcase 1:  1 is equal to 2 raised to 0 (20 == 1).
Testcase2: 98 cannot be obtained by any power of 2.
*/


#include<bits/stdc++.h>
using namespace std;


// Function to check power of two
bool isPowerofTwo(long long n){
    
    // Your code here   
    if(n && !(n & (n-1)))
      return true;
      
    else
      return false;
    
}

int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        if(n<=0) // if n is less than equal to zero then it can't be a power of 2
        {
            cout<<"NO"<<endl; //so we print No
            continue; //continue and check for other values
        }

         if(isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}