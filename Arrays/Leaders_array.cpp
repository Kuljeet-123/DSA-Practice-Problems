/*Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.*/

#include<iostream>
using namespace std;

void printLeaders(int arr[],int n)
{
    int max_from_right=arr[n-1];
    cout << max_from_right << " ";
    for(int i=n-1;i>=0;i--)
    {
        if(max_from_right<arr[i])
        {
            max_from_right=arr[i];
            cout << max_from_right << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter array elements";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    printLeaders(arr,n);

    return 0;
}