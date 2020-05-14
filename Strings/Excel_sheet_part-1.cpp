/*
Excel Sheet | Part - 1
Given a positive integer N, print its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.

Output:
For each testcase, in a new line, print the string corrosponding to the column number.

User Task:
Complete the function ExcelColumn() which takes N as input and returns output string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107

Example:
Input:
1
51
Output:
AY
 */

#include<bits/stdc++.h>
using namespace std;
string ExcelColumn(int n);

//User function template for C++
#define MAX 50 

string ExcelColumn(int n)
{
    // Your code goes here
    char str[MAX]; // To store result (Excel column name) 
    int i = 0; // To store current index in str which is result 
  
    while (n > 0) { 
        // Find remainder 
        int rem = n % 26; 
  
        // If remainder is 0, then a 'Z' must be there in output 
        if (rem == 0) { 
            str[i++] = 'Z'; 
            n = (n / 26) - 1; 
        } 
        else // If remainder is non-zero 
        { 
            str[i++] = (rem - 1) + 'A'; 
            n = n / 26; 
        } 
    } 
    str[i] = '\0'; 
  
    // Reverse the string and print result 
    reverse(str, str + strlen(str));
  
    return str; 
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ExcelColumn(n)<<endl;
    }
    return 0;
}