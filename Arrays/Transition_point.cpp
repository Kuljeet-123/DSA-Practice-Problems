/*Find Transition Point
You are given a sorted array containing only numbers 0 and 1. Find the transition point efficiently. Transition point is a point where "0" ends and "1" begins.
Note that, if there is no "1" exists, print -1.

Input:

You have to complete the method which takes 2 argument: the array arr[] and size of array N. You should not read any input from stdin/console. There are multiple test cases. For each test cases, this method will be called individually.

Output:

Your function should return transition point.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500000
0 ≤ C[i] ≤ 1
Example:

Input
1
5
0 0 0 1 1

Output
3
*/

#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}



// Function to find the transition point
int transitionPoint(int arr[], int n) {
    // code here
    int l=0;
   int high=n-1;
   int mid=0;
   while(l<=high)
   {
       mid=((l+high)/2);
       if(arr[mid]==1 && arr[mid-1]!=1)
       return mid;
       else
       {
           if(arr[mid-1]==1)
           high=mid-1;
           else
           l=mid+1;
       }
   }
   return -1;
}