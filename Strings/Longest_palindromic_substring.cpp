/*
Longest Palindrome Substring
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists of the number of test cases. The following T lines consist of a string each.

Output:
For every test case, print the longest palindromic substring in a new line.

User Task:
You don't need to read input or print anything, printing is done by the driver code, user just needs to complete longestPalindrome() function and return the longest palindromic substring.

Constraints:
1 ≤ T ≤ 100
1 ≤ |Str| ≤ 500

Example:
Input:
1
aaaabbaa
Output:
aabbaa
*/

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string);

// Your code will be pasted here

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << endl;
    }
    return 0;
}

// User function template for C++
int expandPalindromeLength(string& s, int n, int l, int r) {
    while (l >= 0 && r <= n && s[l] == s[r]) {
      --l;
      ++r;
    }
    return (--r) - (++l) + 1;  // r - l - 1
  }

// A : given string
// return the required string
string longestPalindrome(string s) {
    // code here
    int n = (int)s.length();
    int start = 0;    // starting index of current max palindrom
    int max_len = 0;  // max palindrome length seen so far
    for (int i = 0; i < n; ++i) {
      int cur = max(expandPalindromeLength(s, n, i, i),       // case odd
                    expandPalindromeLength(s, n, i, i + 1));  // case even
      if (cur > max_len) {  // update both current max and starting index
        max_len = cur;
        start = i - (max_len - 1) / 2;  // works for both odd and even len
      }
    }
    return s.substr(start, max_len);
}