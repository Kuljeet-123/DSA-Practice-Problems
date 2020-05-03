#include<iostream>
using namespace std;

bool isPal(string str,int s,int e)
{
    if(s==e)
      return true;
    if(s>e)
      return true;
    if(str[s]!=str[e])
       return false;

  return isPal(str,s+1,e-1);

}

int main()
{
    string str;
    cin >> str;
    int s=0;
    int e=str.length()-1;
    cout << isPal(str,s,e);

    return 0;
}