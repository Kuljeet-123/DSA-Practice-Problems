/*
Longest Substring Without Repeating Characters
Given a string S, find the length of its longest substring that does not have any repeating characters.

Input:
The first line of input contains the number of test cases T. Followed by T lines, each containing a string S.

Output:
Print the length of the longest substring that does not have any repeating characters.

Your Task:
Complete SubsequenceLength function that takes string s as input and returns the length of the longest substring that does not have any repeating characters.

Constraints: 
1<=T<=100
0<= S.length() <= 10^5

Example:
Input:
2
geeksforgeeks
abbcdb
Output:
7
3
Explanation:
TestCase 1: The longest substring without repeated characters is "ksforge".
TestCase 2: The longest substring is "bcd". Here "abcd" is not a substring of the given string.
*/

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string s);

//User function Template for C++
#define NO_OF_CHARS 256 

// s is the given string
int SubsequenceLength (string str) 
{
    // Your code goes here
    int n = str.size(); 
  
    int res = 0; // result 
  
    // last index of all characters is initialized 
    // as -1 
    vector<int> lastIndex(NO_OF_CHARS, -1); 
  
    // Initialize start of current window 
    int i = 0; 
  
    // Move end of current window 
    for (int j = 0; j < n; j++) { 
  
        i = max(i, lastIndex[str[j]] + 1); 
  
        // Update result if we get a larger window 
        res = max(res, j - i + 1); 
  
        // Update last index of j. 
        lastIndex[str[j]] = j; 
    } 
    return res; 
}

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<SubsequenceLength(str)<<"\n";
    }
    return 0;
}
