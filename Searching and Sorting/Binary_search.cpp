/*Binary Search
Given a sorted array A[](0 based index) and a key "k"  you need to complete the function bin_search to  determine the position of the key if the key is present in the array. If the key is not  present then you have to return -1. The arguments left and right denotes the left most index  and right most index of the array A[]. There are multiple test cases. For each test case, this function will be called individually.

Input:
The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of 3 lines. First line of each test case contains an integer N denoting the size of the array. Second line of each test case consists of 'N' space separated integers denoting the elements of the array A[]. The third line contains a key 'k' .

Output:
Prints the position of the key if its present in the array else print -1 if the key is not present in the array.

Constraints:
1 <= T <= 100
1 <= N <= 200

Example:
Input:
2
5
1 2 3 4 5 
4
5
11 22 33 44 55
445

Output:
3
-1
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int bin_search(int A[],int left,int right,int k);

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
            cin>>a[i];
        int key;
        cin>>key;
        int found = bin_search(a,0,N-1,key);
        cout<<found<<endl;
    }
}
// } Driver Code Ends


/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
    if(left > right)
      return -1;
    
    int mid = left + (right-left)/2;
    
    if(A[mid] == k)
       return mid;
       
    if(A[mid] > k)
       return bin_search(A,left,mid-1,k);
     
    else
       return bin_search(A,mid+1,right,k);

}