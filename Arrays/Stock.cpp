/*The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/

#include<iostream>
using namespace std;

int maxProfit(int arr[],int start,int end)
{
    if(end<=start)
       return 0;
    int profit=0;
    for(int i=start;i<end;i++)
    {
        for(int j=i+1;j<=end;j++)
        {
            if(arr[j]>arr[i])
            {
                int currProfit=arr[j]-arr[i]+maxProfit(arr,start,i-1)+maxProfit(arr,j+1,end);
                profit=max(profit,currProfit);
            }
        }
    }
    return profit;
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
    cout << "Stock Buy and Sell max profit is:" << maxProfit(arr,0,n-1);

    return 0;
}