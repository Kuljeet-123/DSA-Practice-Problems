/*Given an array (or string), the task is to reverse the array/string.

Examples :

Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}
*/

#include<iostream>
using namespace std;

void reverseArray(int arr[],int start,int end)
{
    if(start>=end)
     return;
    
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    reverseArray(arr,start+1,end-1);
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Array elements";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    reverseArray(arr,0,n-1);
    cout << "Reversed Array is:";
    printArray(arr,n);

    return 0;
}