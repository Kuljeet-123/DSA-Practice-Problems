/*
Maximum Occuring Character
Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs maximum number of time then print the lexicographically smaller character.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of a string in 'lowercase' only in a separate line.

Output:
For each testcase, in a new line, print the lexicographically smaller character which occurred the maximum number of time.

User Task:
The task is to complete the function getMaxOccuringChar() which returns the character which is most occuring.

Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 100

Example:
Input:
2
testsample
output
Output:
e
t

Explanation:
Testcase 1: e is the character which is having highest frequency.
Testcase 2: t and u are the characters with the same frequency, but t is lexicographically smaller.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
    cout<< getMaxOccuringChar(str)<<endl;
    }
}// } Driver Code Ends



// Function to get maximum occuring 
// character in given string str
char getMaxOccuringChar(char* str)
{
    // Your code here
    int freq[26] = { 0 }; 
  
    // to store maximum frequency 
    int max = -1; 
  
    // to store the maximum occurring character 
    char result; 
  
    // length of 'str' 
    int len = strlen(str); 
  
    // get frequency of each character of 'str' 
    for (int i = 0; i < len; i++) 
        freq[str[i] - 'a']++; 
  
    // for each character, where character is obtained by 
    // (i + 'a') check whether it is the maximum character 
    // so far and accodingly update 'result' 
    for (int i = 0; i < 26; i++) 
        if (max < freq[i]) { 
            max = freq[i]; 
            result = (char)(i + 'a'); 
        } 
  
    // maximum occurring character 
    return result; 
}
