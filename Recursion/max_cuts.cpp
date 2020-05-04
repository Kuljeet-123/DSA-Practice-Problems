/*Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts. You must make at least one cut.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is length of rope denoted by N.

Output:

Print the maximizes product of lengths of all parts.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100

Example:

Input:
2
2
5

Output:
1
6
*/

#include<iostream>
using namespace std;

int maxCuts(int n,int a,int b,int c)
{
    if(n==0)
      return 0;
    if(n<0)
      return -1;
    int res=max(max(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c)),maxCuts(n-c,a,b,c));

    if(res==-1)
      return -1;
    
  return (res+1);
}

int main()
{
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    cout << maxCuts(n,a,b,c);

    return 0;
}