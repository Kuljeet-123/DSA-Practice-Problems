/*Parenthesis Checker
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”.

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Your Task:
This is a function problem. You only need to complete the function ispar() that takes string as parameter and returns true if brackets are balanced else returns false. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ |x| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced

Explanation:
Testcase 1: { ( [ ] ) }. Same colored brackets can form balaced pairs, with 0 number of unbalanced bracket.
Testcase 2: () . Same bracket can form balanced pairs, and here only 1 type of bracket is present and in balanced way.
Testcase 3: ([] . Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
*/


#include<bits/stdc++.h>
using namespace std;

// Function to return if the paranthesis are balanced or not
bool ispar(string str)
{
    // Your code here
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i=0; i<str.length(); i++) 
    { 
        if (str[i]=='('||str[i]=='['||str[i]=='{') 
        { 
            // Push the element in the stack 
            s.push(str[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.empty()) 
           return false; 
  
        switch (str[i]) 
        { 
        case ')': 
  
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    // Check Empty Stack 
    return (s.empty()); 
}


int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}