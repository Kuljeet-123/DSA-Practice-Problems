/*Largest subarray with 0 sum 
Given an array having both positive and negative integers. The task is to complete the function maxLen() which returns the length of maximum subarray with 0 sum. The function takes two arguments an array A and n where n is the size of the array A.

Input:
The first line of input contains an element T denoting the number of test cases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains a number denoting the size of the array A. Then in the next line are space-separated values of the array A.

Output:
For each test case, the output will be the length of the largest subarray which has sum 0.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function maxLen().

Expected Time Complexity: O(N*Log(N)).
Expected Space Complexity: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i

Example:
Input
1
8
15 -2 2 -8 1 7 10 23

Output
5

Explanation
Testcase 1: In the above test case the largest subarray with sum 0 will be -2 2 -8 1 7.
*/


#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}

int maxLen(int A[], int n) {
    // Your code here
    unordered_map<int, int> presum; 
  
    int sum = 0; // Initialize the sum of elements 
    int max_len = 0; // Initialize result 
  
    // Traverse through the given array 
    for (int i = 0; i < n; i++) { 
        // Add current element to sum 
        sum += A[i]; 
  
        if (A[i] == 0 && max_len == 0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i + 1; 
  
        // Look for this sum in Hash table 
        if (presum.find(sum) != presum.end()) { 
            // If this sum is seen before, then update max_len 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            // Else insert this sum with index in hash table 
            presum[sum] = i; 
        } 
    } 
  
    return max_len; 
}
