/*Merge Sort
The task is to complete merge() function which is used to implement Merge Sort.

Input:
First line of the input denotes number of test cases 'T'. First line of the testcase is the size of array and second line consists of array elements separated by space.

Output:
Sorted array in increasing order is displayed to the user.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function merge().

Constraints:
1 <= T <= 50
1 <= N <= 105
1 <= arr[i] <= 103

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation:
Testcase 1: The array after performing mergesort is: 1 3 4 7 9.
*/
// { Driver Code Starts
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     // Your code here m==l n==r
     int temp[r-l+1];
     int i=l;
     int j=m+1;
     int k=0;
     while(i<=m&& j<=r)
     {
         if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
         else 
            temp[k++]=arr[j++];
         
     }
     while(i<=m)
       temp[k++]=arr[i++];
     while(j<=r)
       temp[k++]=arr[j++];
     for(int c=l;c<=r;c++)
     {
         arr[c]=temp[c-l];
     }
}