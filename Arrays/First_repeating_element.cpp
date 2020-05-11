/*First Repeating Element
Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Input :
The first line contains an integer T denoting the total number of test cases. In each test cases, First line is number of elements in array N and second its values.

Output:
Complete firstRepeated function and return the index of first repeated element, if there is not any repeating element then return “-1” (without quotes). Use 1 Based Indexing.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 106

Example:
Input:
3
7
1 5 3 4 3 5 6
4
1 2 3 4
5
1 2 2 1 3

Output:
2
-1
1

Explanation: 
Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is less than 3 whose first occuring index is 3.
Testcase 2: All elements appear only once so -1 is printed.
Tescase 3:  The element 1 appears more than 1 times and is the first element to do so. So, we print its index 1.
*/


#include<bits/stdc++.h>
using namespace std;


unordered_map<int, int> um;


int firstRepeated(int *, int);

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
            
        cout << firstRepeated(arr,n) << "\n";
    }

    return 0;
}

//User function template in C++


// arr : given array
// n : size of the array

int firstRepeated(int arr[], int n) {
    //code here
     unordered_map<int,int> m;
	    for(int i=0; i<n; i++)
	    {
	        m[arr[i]]++;
	    }
	    
	    int i=0;
	    while(m[arr[i]] == 1 && i<n)
	        i++;
	   if(i<n)     
	        return i+1;
	   else
	        return -1;
}
