#include<iostream>
using namespace std;

int Jos(int n,int k)
{
    if(n==1)
      return n;

  return (Jos(n-1,k)+k-1)%n + 1;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    cout << Jos(n,k);

    return 0;
}