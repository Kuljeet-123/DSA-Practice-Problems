/*Reverse a string using Stack
An string of words is given, the task is to reverse the string using stack.

Input Format:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string s of words without spaces.

Output Format:
For each test case ,print the reverse of the string in new line. 

Your Task:
Since this is a function problem, you don't need to take any input. Just complete the provided function.

Constraints:
1 <= T <= 100
1 <= length of the string <= 100

Example:
Input:
2
GeeksQuiz
GeeksforGeeks
Output:
ziuQskeeG
skeeGrofskeeG
*/


#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}


class Stack  
{  
    public: 
    int top;  
    unsigned capacity;  
    char* array;  
};  
  
// function to create a stack of given  
// capacity. It initializes size of stack as 0  
Stack* createStack(unsigned capacity)  
{  
    Stack* stack = new Stack(); 
    stack->capacity = capacity;  
    stack->top = -1;  
    stack->array = new char[(stack->capacity * sizeof(char))];  
    return stack;  
}  
  
// Stack is full when top is equal to the last index  
int isFull(Stack* stack)  
{ return stack->top == stack->capacity - 1; }  
  
// Stack is empty when top is equal to -1  
int isEmpty(Stack* stack)  
{ return stack->top == -1; }  
  
// Function to add an item to stack.  
// It increases top by 1  
void push(Stack* stack, char item)  
{  
    if (isFull(stack))  
        return;  
    stack->array[++stack->top] = item;  
}  
  
// Function to remove an item from stack.  
// It decreases top by 1  
char pop(Stack* stack)  
{  
    if (isEmpty(stack))  
        return -1;  
    return stack->array[stack->top--];  
}  
  

void reverse(char *str, int len)
{

// Your code goes here
Stack* stack = createStack(len);  
  
    // Push all characters of string to stack  
    int i;  
    for (i = 0; i < len; i++)  
        push(stack, str[i]);  
  
    // Pop all characters of string and  
    // put them back to str  
    for (i = 0; i < len; i++)  
        str[i] = pop(stack);  

}