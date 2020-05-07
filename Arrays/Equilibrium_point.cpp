/*Equilibrium point
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.
Note: The output should be based on 1-based indexing, i.e. if the equilibrium point occurs at 1st position then output would be 1.

User Task:
The task is to complete the function equilibriumPoint() which returns the point of equilibrium.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).
*/

// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {

    // Your code here
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return -1;
    }
    int left_sum=a[0], i=0;
    int right_sum=a[n-1], j=n-1;
    int point = -1;
    while(i+2<j)
    {
        if(left_sum < right_sum)
        {
            i++;
            left_sum+=a[i];
        }
        else
        {
            j--;
            right_sum+=a[j];
        }
    }
    if(left_sum == right_sum)
    {
        return i+2;
    }
    else
    {
        return -1;
    }
    
}