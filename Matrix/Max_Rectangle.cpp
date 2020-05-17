/*Max rectangle
Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case are 2 integers n and m denoting the size of the matrix M . Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=100
1<=n,m<=1000
0<=M[][]<=1

Example:
Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}

int maxrec(int a[],int n)
{
    stack<int> s;
    int i=0, curr, area, max=INT_MIN;
    while(i<=n)
    {
        if(i==n)
        {
            while(!s.empty())
            {
                curr=s.top();
                s.pop();
                if(s.empty())
                {
                    area =a[curr]*i;
                    if(area>max) max=area;
                }
                else
                {
                    area=a[curr]*(i-s.top()-1);
                    if(area>max) max=area;
                }
            }
        }
        else
        {
            if(s.empty()||a[i]>=a[s.top()])
                s.push(i);
            else
            {
                while(!s.empty()&&(a[s.top()]>=a[i]))
                {
                    curr=s.top();
                    s.pop();
                    if(s.empty())
                    {
                        area =a[curr]*i;
                        if(area>max) max=area;
                    }
                    else
                    {
                        area=a[curr]*(i-s.top()-1);
                        if(area>max) max=area;
                    }
                }
                s.push(i);
            }
        }
        i++;
    }
    return max;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int c,a[m]={}, max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==1) a[j]+=M[i][j];
            else a[j]=0;
        }
        c=maxrec(a,m);
        if(c>max) max=c;
    }
    return max;
}
