/*Given an array of integers of size 'n' .Our aim is to calculate the maximum sum of 'k'
consecutive elements in an array
Note:Sliding Window technique is used.
*/

#include<iostream>
using namespace std;

int maxSum(int arr[],int n,int k)
{
    if(n<k)
    {
        cout << "Invalid";
        return -1;
    }
    int res=0;
    for(int i=0;i<k;i++)
       res+=arr[i];
    
    int current_sum=res;
    for(int i=k;i<n;i++)
    {
        current_sum+=arr[i]-arr[i-k];
        res=max(res,current_sum);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int arr[n];
    cout << "Enter Array values:";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter value of k:";
    cin >> k;
    cout << "Maximum sum of k consecutive elements is:" << maxSum(arr,n,k);

    return 0;
}