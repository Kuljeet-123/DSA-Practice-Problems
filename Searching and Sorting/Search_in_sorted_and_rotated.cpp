/*Search in a Sorted and Rotated Array
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer N denoting the size of the given array. The second line of each test case contains N space-separated integers denoting the elements of the array A. The third line of each test case contains an integer K denoting the element to be searched in the array.

Output:
For each test case, print the index of the element K in a new line, if K does not exist in the array then print -1.

User Task:
Complete Search() function and return the index of the element K if found in the array. If the element is not present, then return -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ Ai ≤ 108
1 ≤ K ≤ 108

Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1

Explanation:
Testcase 1: 10 is found at index 5.
*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int binary_search(vector<int> arr, int i, int j, int k)
{
    if(i>j)
        return -1;
    
    int mid = (i+j)/2;
    
    if(arr[mid] == k)
        return mid;
        
    if(arr[i] < arr[mid])
    {
        if(k>=arr[i] && k<arr[mid])
            return binary_search(arr, i, mid-1, k);
        
        else 
            return binary_search(arr, mid+1, j, k);
    }
    
    else 
    {
        if(k>arr[mid] && k<=arr[j])
            return binary_search(arr, mid+1, j, k);
        else
            return binary_search(arr, i, mid-1, k);
    }
}


int Search(vector<int> v, int k) {
    //code here
    int n=v.size();
  return binary_search(v,0,n-1,k);
    
        
}