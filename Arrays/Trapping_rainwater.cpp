/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
*/

#include<iostream>
using namespace std;

int maxWater(int arr[],int n)
{
    int res=0;
    int left_max=0,right_max=0;
    int low=0,high=n-1;
    while(low<=high)
    {
        if(arr[low]<arr[high])
        {
            if(arr[low]>left_max)
               left_max=arr[low];
            else 
                res+=left_max- arr[low];
           low++;
        }
        else{
            if(arr[high]>right_max)
               right_max=arr[high];
            else 
                res+=right_max-arr[high];
          high--;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Array values";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum rainwater is:" << maxWater(arr,n) << " ";
    
    return 0;
}