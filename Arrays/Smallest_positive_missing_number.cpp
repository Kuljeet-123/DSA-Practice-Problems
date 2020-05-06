/*Smallest Positive missing number
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

User Task:
The task is to complete the function findMissing() which finds the smallest positive missing number.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find missing integer in array
// arr: input array
// n: size of array
int findMissing(int arr[], int n) { 
    
    // Your code here
    int val;
    int nextval;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=0 || arr[i]>n)
           continue;
         
        val=arr[i];
        
        while (arr[val - 1] != val) { 
            nextval = arr[val - 1]; 
            arr[val - 1] = val; 
            val = nextval; 
            if (val <= 0 || val > n) 
                break; 
        } 
    }
    
    
    for (int i = 0; i < n; i++) { 
        if (arr[i] != i + 1) { 
            return i + 1; 
        } 
    } 
  
  return n+1;    
}

// { Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        cout<<findMissing(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends