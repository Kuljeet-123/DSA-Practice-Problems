// { Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

void printIntersection(int arr1[], int arr2[], int N, int M);  
  
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        
        // Function calling 
        printIntersection(arr1, arr2, N, M); 
        
        cout << endl;
    }
    
  return 0; 
} 
// } Driver Code Ends


/* Function prints Intersection of arr1[] and arr2[] 
N is the number of elements in arr1[] 
M is the number of elements in arr2[] */
void printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    //Your code here
    int i=0,j=0;
    while(i < N && j < M)
    {
        if(arr1[i] < arr2[j])
        {
            j++;
        }
        else if(arr2[j < arr1[i]])
        {
            i++;
        }
        else if(arr1[i]==arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else
        {
            cout << "-1";
        }
    }
}
