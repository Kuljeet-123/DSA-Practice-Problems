/*
Remainder with 7
Given a number as string(n) , your task is to complete the function remainderWith7 which returns an integer which denotes the remainder of the number when its divided by 7. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow . Each test case contains a number represented as string.

Output:
For each test case in a new line print the remainder when the number is divided by 7.

Constraints:
1<=T<=100
1<=length of n <=300

Example(To be used only for expected output):
Input:
2
5
8
Output:
5
1

*/

// { Driver Code Starts
#include <iostream>
using namespace std;
int remainderWith7(string );

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
string n;
cin>>n;

cout<<remainderWith7(n)<<endl;

}
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */
int remainderWith7(string num)
{
    //Your code here
    int series[] = {1, 3, 2, -1, -3, -2}; 
   
    int series_index = 0; 
  
    int result = 0;  
    for (int i=num.size()-1; i>=0; i--) 
    { 
        int digit = num[i] - '0'; 
        result += digit * series[series_index]; 
        series_index = (series_index + 1) % 6; 
        result %= 7; 
    } 
  
    if (result < 0) 
      result = (result + 7) % 7; 
  
    return result; 
}