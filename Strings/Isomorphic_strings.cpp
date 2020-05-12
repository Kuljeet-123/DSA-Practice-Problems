/*
Isomorphic Strings
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic, if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.

Input:
The first line contains an integer T, depicting total number of test cases. Each test case contains two strings each in new line.

Output:
Print "1" if strings are isomorphic and "0" if not.

User Task:
The task is to complete the function areIsomorphic() which checks if two strings are isomorphic. The function returns true if strings are isomorphic else it returns false.

Constraints:
1 <= T <= 100
1 <= Length of Strings <= 103

Example:
Input:
2
aab
xxy
aab
xyz
Output:
1
0

Explanation:
Testcase 1: There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Testcase 2: There are two different characters in aab but there are three different characters in xyz. So there wont't be one to one mapping between str1 and str2.
 */

// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}

// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    
    // Your code here
     int m = str1.length(), n = str2.length(); 
  
    if (m != n) 
      return false; 
  
    bool marked[MAX_CHARS] = {false}; 
  
    int map[MAX_CHARS]; 
    memset(map, -1, sizeof(map)); 
  
    for (int i = 0; i < n; i++) 
    { 
        if (map[str1[i]] == -1) 
        { 
            if (marked[str2[i]] == true) 
                return false; 
  
            marked[str2[i]] = true; 
  
            map[str1[i]] = str2[i]; 
        } 
  
        else if (map[str1[i]] != str2[i]) 
            return false; 
    } 
  
    return true; 
    
}