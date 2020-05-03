/*Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array. First index means, the index of first occurrence of x in the input array. Do this recursively. Indexing in the array starts from 0.

Input Format:

Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format: first index or -1

Constraints: 1 <= N <= 10^3

Example

    Input:
    4
    9 8 10 8
    8

    Output:
    1
    */
#include<iostream>
using namespace std;

int firstIndex(int arr[],int n,int target,int currentIndex)
{
    if(currentIndex==n)
      return -1;
    if(arr[currentIndex]==target)
      return currentIndex;

  return firstIndex(arr,n,target,currentIndex+1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Array values";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target value ";
    cin >> target;
    cout << firstIndex(arr,n,target,0);

    return 0;
}