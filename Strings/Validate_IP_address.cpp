/*
Validate an IP Address
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string ip as its only argument .

Input:
The first line of each test case contains an integer T denoting the number of test case . Then T test cases follow . Each test case takes a string ip.

Output:
For each test case output will be 1 if the string is a valid ip address else 0.

Constraints:
1<=T<=100
1<=length of string <=50

Example(To be used only for expected output) :
Input
4
222.111.111.111
5555..555
0000.0000.0000.0000
1.2.3.04

Output
1
0
0
0
*/

#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        cout << isValid(s) << endl;
    }
    return 0;
}

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
int isValid(char *ip) {
    // your code here
    try{
    int j=0;
       string s;
     long long p=0;
     vector<long long> v;
     
     while(1){
       if(ip[j]=='\0') {
         if(s[0]=='0' && s[1]>='0') return 0;
         p=stoi(s); v.push_back(p);break;}
        
        if(ip[j]!='.' ){ s+=ip[j];j++;continue;}
        
        if(s[0]!='\0') 
      {   if(s[0]=='0' && s[1]>='0') return 0;
          p=stoi(s);
          v.push_back(p);
       }
       if(ip[j]=='.'){ j++;s="";}
      }
      
      
      int count=0;
      for(int i=0;i<v.size();i++)   if(v[i]>=0 &&v[i]<=255)  count++;
        if(count==4) return 1;
        else return 0;
     }    
    catch(exception){ return 0;}  //exceptionn handling
      
}