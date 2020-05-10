/*
Convert to Roman No
Given an integer n your task is to complete the function convertToRoman which prints the corresponding roman number of n .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a single integer n.

Output:
Complete convertToRoman function and return the roman number representation of n. 

Constraints:
1<=T<=100
1<=n<5000

Example:
Input
2
5
3
Output
V
III 
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void convertToRoman(int ) ;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		
	convertToRoman(N);
	cout<<endl;
		
	}
	return 0;
}// } Driver Code Ends


/*you are required to complete 
this function*/

// n :given number that you are require to convert
void convertToRoman(int n) 
{
//Your code here
map<int,string>mp;
mp[1000]="M";
mp[900]="CM";
mp[500]="D";
mp[400]="CD";
mp[100]="C";
mp[90]="XC";
mp[50]="L";
mp[40]="XL";
mp[10]="X";
mp[9]="IX";
mp[5]="V";
mp[4]="IV";
mp[1]="I";

for(auto i=mp.rbegin();i!=mp.rend();i++)
{
    while(n>=i->first)
    {
        cout<<i->second;
        n-=i->first;
    }
}
}