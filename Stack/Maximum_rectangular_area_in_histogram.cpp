/*Maximum Rectangular Area in a Histogram
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

User Task:
The task is to complete the function getMaxArea() which finds the largest rectangular area possible, and return the answer.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 1018

Example:
Input: 
2
7
6 2 5 4 5 1 6
8
7 2 8 9 1 3 6 5
Output:
12
16

Explanation:
Testcase1:

Testcase 2: Maximum size of the histogram will be 8  and there will be 2 consecutive histogram. And hence the area of the histogram will be 8x2 = 16.
*/


#include <bits/stdc++.h>
using namespace std;

// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<int> s; 
  
    long long max_area = 0; // Initialize max area 
    long long tp;  // To store top of stack 
    long long area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    int i = 0; 
    while (i < n) 
    { 
        if (s.empty() || arr[s.top()] <= arr[i]) 
            s.push(i++); 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            area_with_top = arr[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = arr[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
    
}

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}