/*Absolute Value
You are given an interger I. You need to print the absolute value of the interger I.

Input:
The first line of input contains T, denoting number of testcases. Each testcase contains single integer I which may be positive or negative.

Output:
For each testcase, in a new line, output the absolute value.

Your Task:
This is function problem. You only need to complete the function absolute that takes integer I as parameter and returns the absolute value of I. All other things are taken care of by the driver code.

Constraints:
1 <= T <= 100
-106 <= I <= 106

Example:
Input:
2
-32
45
Output:
32
45

Explanation:
Testcase 1: Since -32 is negative, we prints its positive equavalent, i.e., 32
Testcase 1: Since 45 is positive, we prints its value as it is, i.e., 45
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int absolute(int I);

int main() {
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--) {
        int I;
        cin >> I;
        cout << absolute(I) << endl; // print the output
    }
    return 0;
}// } Driver Code Ends


// User function Template for C++

// Should return absolute value of I
// You need to complete this function
int absolute(int I) {
    // Your code here
    return abs(I);
}
