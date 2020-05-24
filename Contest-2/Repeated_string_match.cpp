/*
Given two strings A and B, find the minimum number of times A has to be stated such that B becomes a substring of the repeated A. If no such solution exists, return -1.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines containing A and B respectively. 

Output:
Print the minimum number of times A needs to be repeated. If no solution exists, return -1.

Your Task:
Complete the function repeatedStringMatch() that takes strings A and B as input and returns integer output.

Constraints: 
1 <= T <= 100
1<= A.length() <= 1000
1<= B.length() <= 1000

Example:
Sample Input :
2
abcd
cdabcdab
aa
a

Sample Output :
3
1

Explanation : 
Testcase 1: After repeating A 3 times, we get ‘abcdabcdabcd’. B is now a substring of A.

Testcase 2: B is already a substring of A and need to be stated only once. 
*/

#include <bits/stdc++.h>
using namespace std;
int repeatedStringMatch(string A, string B);

int repeatedStringMatch(string A, string B){
    int count=1;string rep=A;
 //First make length of A >=B
 while(A.length()<B.length())
 {
     A=A+rep;
     count++;
 }
 if(A.find(B)!=string::npos) return count;
 A=A+rep;count++; //Check by one more repetition
 if(A.find(B)!=string::npos) return count;
 return -1;
}


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        cout<<repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
