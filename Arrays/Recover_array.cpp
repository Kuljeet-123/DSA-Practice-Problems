/*An array is given we have to first remove the middle element from array and store into another array
and then recover back our original array.
For eg:
if array a={1,2,3,4,5}
then this is the middle array b={3,2,4,1,5}
And we have to pass this middle array as input and recover back our original array.
Input:- 

b={3,2,4,1,5}


output:-
{1,2,3,4,5}
 */

#include<iostream>
using namespace std;

void recoverArray(int input[],int n,int output[])
{
    int left,right;
    int mid=n/2;
    
    int i=0;
    if(n%2!=0)
    {
        output[mid]=input[i];
        left=mid-1;
        right=mid+1;
        i++;
    }
    else
    {
        left=mid-1;
        right=mid;
    }
    
    while(i<n)
    {
        output[left]=input[i];
        left--;
        i++;
        output[right]=input[i];
        right++;
        i++;
    }
}

int main()
{
    int input[1000];
    int n;
    int output[1000];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> input[i];
    }

    recoverArray(input,n,output);

    for(int i=0;i<n;i++)
    {
        cout << output[i] << " ";
    }

}

