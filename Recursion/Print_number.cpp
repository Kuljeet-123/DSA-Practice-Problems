#include<iostream>
using namespace std;

void print(int n)
{
    if(n==0)
    return ;

    cout << n << " ";
    print(n-1);    // This is Tail Recursive and it is much faster 
}
/*
void print2(int n)
{
    if(n==0)
    return ;
    print2(n-1);    //this is not tail recursive that's why it is slower
    cout << n << " ";
}
*/

int main()
{
    int n;
    cin >> n;
    print(n);
    cout << endl;
    //print2(n);
    return 0;
}