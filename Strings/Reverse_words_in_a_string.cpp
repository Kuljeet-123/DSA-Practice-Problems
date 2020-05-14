/*
Reverse words in a given string
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

User Task:
The task is to complete the function reverseWords() which reverse words from the given string and prints the answer. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno
Output:
much.very.program.this.like.i
mno.pqr
*/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}

/*Function to reverse words*/
void reverseWords(char *a) {
    
    // Your code here
    int n=strlen(a);
  int i;
  int last=n-1;
  int start=n-1;
  while(a[start]!='.' && start>=0 )
    {
      start--;
    }
  for(i=start+1;i<=last;i++)
    {
      printf("%c",a[i]);
    }
  start--;
  last=start;
  while(start>=0)
  {
    printf(".");  
    while(a[start]!='.' && start>=0 )
    {
      start--;
    }
    for(i=start+1;i<=last;i++)
    {
      printf("%c",a[i]);
    }
    
    start--;
    last=start;
  }
}

