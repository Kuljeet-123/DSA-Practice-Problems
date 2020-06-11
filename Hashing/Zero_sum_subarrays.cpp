/*Zero Sum Subarrays 
You are given an array A of size N. You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each testcase, in a new line, print the total count of sub-arrays having their sum equal to 0.

Your Task:
Complete findSubarray function that takes array and its size as arguments and returns the total count of sub-arrays with 0 sum. The printing is done by the driver code.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6 -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4

Explanation:
Testcase1: The 6 subarrays are [0], [0], [0], [0], [0 0], and [0 0].
Testcase2: The 4 subarrays are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]
*/


#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    //code here
     int sum=0,count=0;
    unordered_map<int,int>ump;
    ump[0]++;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(ump.find(sum)!=ump.end()){
                count+=ump[sum];
            }
        ump[sum]++;
    }
    return count;
}
