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