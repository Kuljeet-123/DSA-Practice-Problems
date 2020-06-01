/*Stock span problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

User Task:
The task is to complete the function calculateSpan() which finds the span of stock's price for all n days.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80
Output:
1 1 1 2 1 4 6
1 1 2 4 5 1



Explanation:
Testcase 1: Traversing the given input span for 100 will be 1,80 is smaller than 100 so the span is 1 , 60 is smaller than 80 so the span is 1 , 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.
Testcase 2: Traversing the given input span for 10 will be 1, 4 is smaller than 10 so the span will be 1 , 5 is greater than 4 so the span will be 2 and so on. Hence, the output will be 1 1 2 4 5 1.
*/


#include<bits/stdc++.h>
using namespace std;


// Function to calculate span
// price[]: price array in input
// n: size of array
void calculateSpan(int price[], int n, int S[])
{
   // Your code here
   stack<int> st; 
    st.push(0); 
  
    // Span value of first element is always 1 
    S[0] = 1; 
  
    // Calculate span values for rest of the elements 
    for (int day = 1; day < n; day++) { 

        while (!st.empty() && price[st.top()] <= price[day]) 
            st.pop(); 
  
        S[day] = (st.empty()) ? (day + 1) : (day - st.top()); 
  
        // Push this element to stack 
        st.push(day); 
    } 
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}