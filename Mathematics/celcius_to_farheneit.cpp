/*Convert Celsius To Fahrenheit
Given a temperature in celsius C. You need to convert the given temperature to Fahrenheit.

Input:
The first line of input contains T, denoting number of testcases. Each testcase contains single integer C denoting the temperature in celsius.

Output:
For each testcase, in a new line, output the temperature in fahrenheit.

Your Task:
This is a function problem. You only need to complete the function CtoF that takes C as parameter and returns temperature in fahrenheit( in double). The flooring and printing is automatically done by the driver code.

Constraints:
1 <= T <= 100
1 <= C <= 104

Example:
Input:
2
32
50
Output:
89
122

Explanation:
Testcase 1: Using the conversion formula of celsius to farhenheit , it can be calculated that, for 32 degree C, the temperature in Fahrenheit = 89.
Testcase 2: Using the conversion formula of celsius to farhenheit , it can be calculated that, for 50 degree C, the temperature in Fahrenheit = 122.
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


//You need to complete this function
double cToF(int C)
{
    //Your code here
    int F;
    F=(C*9)/5 + 32;
    
  return F;
}


int main()
{
    int T;//number of testcases
    int C,F;
    cin >> T; //input number of testcases
    while(T--){
        cin >> C;//input temperature in celscius
        cout << floor(cToF(C)) << endl; //print the output
    }
    return 0;
} 