#include<iostream>
using namespace std;

void printSub(string str,string current="",int index=0)
{
    if(index==str.length())
    {
        cout << "'" << current <<"'" << " ";
        return ;
    }

    printSub(str,current,index+1);
    printSub(str,current+str[index],index+1);
}

int main()
{
    string str;
    cin >> str;
    printSub(str);

    return 0;
}