/*Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
using Juggling Algorithm method
*/
#include<iostream>
#include<algorithm>
using namespace std;

void rotateArray(int arr[],int d,int n)
{
    d=d%n;
    int g_c_d=__gcd(d,n);
    for(int i=0;i<g_c_d;i++)
    {
        int temp=arr[i];
        int j=i;
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp;
    }
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
    cout << "Enter array elements";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int d;
    cout <<"Enter value of d ";
    cin >> d;
    rotateArray(arr,d,n);
    printArray(arr,n);

    return 0;
}