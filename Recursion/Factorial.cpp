#include<iostream>
using namespace std;
//Tail recursive function for factorial
int fact(int n,int k=1)
{
    if(n==0)
      return k;

  return fact(n-1,n*k); //Tail recursive 
}

int main()
{
    int n;
    cin >> n;
    int k=1;
    cout << fact(n,k);

    return 0;
}