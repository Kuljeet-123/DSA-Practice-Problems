/*Given an array arr of size N and an integer X. The task is to find all the indices of the integer X in the array

Examples:

Input: arr = {1, 2, 3, 2, 2, 5}, X = 2
Output: 1 3 4
Element 2 is present at indices 1, 3, 4 (0 based indexing)*/

#include<iostream>
using namespace std;

int allIndeces(int input[],int n,int target,int output[])
{
    if(n==0)
     return 0;
    
    int res=allIndeces(input+1,n-1,target,output);

    if(input[0]==target)
    {
        for(int i=res-1;i>=0;i--)
        {
            output[i+1]=output[i]+1;
        }
    output[0]=0;
    res++;
    }
    else
    {
        for(int i=res-1;i>=0;i--)
        {
            output[i]=output[i]+1;
        }
    }
    return res;
    
}

void indecesDisplay(int input[],int n,int target)
{
    int output[n];
    int size=allIndeces(input,n,target,output);
    for(int i=0;i<size;i++)
    {
        cout << output[i] << " ";
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Array values";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter Target value";
    cin >> target;
    indecesDisplay(arr,n,target);
    return 0;
}