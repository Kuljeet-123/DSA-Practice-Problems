/*Maximum of minimum for every window size 
Given an integer array A[] of size N. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to n.

Input:
The first line contains an integer T denoting the total number of test cases. In each test cases, the first line contains an integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
In each seperate line, print the array of numbers of size N for each of the considered window size 1, 2 , ..., N respectively.

User Task:
The task is to complete the function printMaxOfMin() which finds the maximum of minimum of every window size.
Expected Time Complxity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 50
1 <= N <= 105
1 <= A[i] <= 106

Example:
Input: 
2
7
10 20 30 50 10 70 30
3
10 20 30
Output: 
70 30 20 10 10 10 10 
30 20 10

Explaination:
Testcase 1:
First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are {10}, {20}, {30}, {50}, {10}, {70} and {30}. Maximum of these minimums is 70.
Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are {10}, {20}, {30}, {10}, {10}, and {30}. Maximum of these minimums is 30.
Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are {10}, {20}, {10}, {10} and {10}. Maximum of these minimums is 20.
Similarly other elements of output are computed.
Testcase 2: First element in output indicates maximum of minimums of all windows of size 1.Minimums of windows of size 1 are {10} , {20} , {30}. Maximum of these minimums are 30 and similarly other outputs can be computed. 
*/


#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void printMaxOfMin(int arr[], int n);
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        printMaxOfMin(a, n);
    }
    return 0;
}


// Function to print maximum of minimum of every window size
// arr[]: input array
// n: size of array
void printMaxOfMin(int arr[], int n) {
    // Your code here
    stack<int> s;  
  
    // Arrays to store previous and next smaller 
    int left[n+1];   
    int right[n+1];  
  
    // Initialize elements of left[] and right[] 
    for (int i=0; i<n; i++) 
    { 
        left[i] = -1; 
        right[i] = n; 
    } 
  
    // Fill elements of left[] using logic discussed on 
    for (int i=0; i<n; i++) 
    { 
        while (!s.empty() && arr[s.top()] >= arr[i]) 
            s.pop(); 
  
        if (!s.empty()) 
            left[i] = s.top(); 
  
        s.push(i); 
    } 
  
    // Empty the stack as stack is  
// going to be used for right[] 
    while (!s.empty()) 
        s.pop(); 
  
    // Fill elements of right[] using same logic 
    for (int i = n-1 ; i>=0 ; i-- ) 
    { 
        while (!s.empty() && arr[s.top()] >= arr[i]) 
            s.pop(); 
  
        if(!s.empty()) 
            right[i] = s.top(); 
  
        s.push(i); 
    } 
  
    // Create and initialize answer array 
    int ans[n+1]; 
    for (int i=0; i<=n; i++) 
        ans[i] = 0; 
  
    // Fill answer array by comparing minimums of all 
    // lengths computed using left[] and right[] 
    for (int i=0; i<n; i++) 
    { 
        // length of the interval 
        int len = right[i] - left[i] - 1; 
  
        // arr[i] is a possible answer for this length  
        // 'len' interval, check if arr[i] is more than 
        // max for 'len' 
        ans[len] = max(ans[len], arr[i]); 
    } 
  
    // Some entries in ans[] may not be filled yet. Fill  
    // them by taking values from right side of ans[] 
    for (int i=n-1; i>=1; i--) 
        ans[i] = max(ans[i], ans[i+1]); 
  
    // Print the result 
    for (int i=1; i<=n; i++) 
        cout << ans[i] << " "; 
   cout << endl;
}