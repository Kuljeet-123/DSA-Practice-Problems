/*Median of Two sorted arrays
Given two sorted arrays arr[] and brr[] of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.

Input Format:
First line of input contains number of testcases T. First line of input contains number of elements in both arrays N and M respectively. Next two lines contains the array elements.

Output Format:
For each testcase, in a new line, print the median.

Your Task:
Complete findMedian function and return the median of two sorted arrays. If there are total even elements, we need to return floor of average of middle two elements.

Constraints:
1 <= T <= 100
1 <= N, M <= 106
1 <= arr[i], brr[i] <= 107

Example:
Input:
4
5 6
1 2 3 4 5
3 4 5 6 7 8
2 3
1 2
2 3 4
4 4
1 2 3 4
11 12 13 14
4 3
1 2 3 4
2 3 4

Output:
4
2
7
3

Explanation:
Testcase 1: After merging two arrays, elements will be as 1 2 3 3 4 4 5 5 6 7 8. So, median is 4.
Testcase 2: After merging two arrays, elements will be as 1 2 2 3 4. So, median is 2.
Testcase 3: After merging two arrays, elements will be as 1 2 3 4 11 12 13 14. So, median is (4+11)/2=7.
Testcase 4: After merging two arrays, elements will be as 1 2 2 3 3 4 4. So, median is 3.
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int findMedian(int *, int , int *, int);

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    
	    if(n < m)
	        cout << findMedian(arr, n, brr, m) << endl;
	   else
	        cout << findMedian(brr, m, arr, n) << endl;
	    
	}

}// } Driver Code Ends


//User function template for C++

// arr : given array with size n 
// brr : given array with size m
int findMedian(int arr1[], int n, int arr2[], int m){
    // code here
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;  
    int m1 = -1, m2 = -1;  
  
    // Since there are (n+m) elements,  
    // There are following two cases  
    // if n+m is odd then the middle  
    //index is median i.e. (m+n)/2  
    if((m + n) % 2 == 1)  
    {  
        for (count = 0; count <= (n + m)/2; count++) 
        {  
            if(i != n && j != m) 
            {  
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];  
            }  
            else if(i < n) 
            {  
                m1 = arr1[i++];  
            }  
            // for case when j<m,  
            else
            {  
                m1 = arr2[j++];  
            }  
        }  
        return m1;  
    }  
      
    // median will be average of elements  
    // at index ((m+n)/2 - 1) and (m+n)/2  
    // in the array obtained after merging ar1 and ar2  
    else 
    {  
        for (count = 0; count <= (n + m)/2; count++)  
        {  
            m2 = m1;  
            if(i != n && j != m) 
            {  
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];  
            }  
            else if(i < n) 
            {  
                m1 = arr1[i++];  
            }  
            // for case when j<m,  
            else
            {  
                m1 = arr1[j++];  
            }  
        }  
        return (m1 + m2)/2;  
    }  
}