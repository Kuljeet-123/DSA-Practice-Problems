/*Number is sparse or not
Given a number N.  The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set  in the binary representation.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is number 'N'.

Output:
Print '1' if the number is sparse and '0' if the number is not sparse.

User Task:
The task is to complete the function checkSparse() that takes n as parameter and returns true if the number is sparse else returns false.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
2
3

Output:
1
0

Explanation:
Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number.
*/

#include<iostream>
using namespace std;

// function to check if the number is sparse
// n : is the number to check if it is sparse
bool isSparse(int n){
    
    // Your code
     if (n & (n >> 1)) 
        return false; 
  
    return true; 
    
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        if(isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}