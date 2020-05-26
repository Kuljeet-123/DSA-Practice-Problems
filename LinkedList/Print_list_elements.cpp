/*Print Linked List elements
You are given the pointer to the head node of a linked list. You have to print all of its elements in order in a single line.

Input:
You have to complete a method which takes one argument: the head of the linked list. You should not read any input from stdin/console. The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. There are multiple test cases. For each test case, this method will be called individually.

Output:
Print the elements of the linked list in a single line separated by a single space.

User Task:
The task is to complete the function display() which prints the elements of the linked list.

Example:
Input:
2
2
1 2
1
4

Output:
1 2
4

Explanation:
Testcase 1: Here the first line denotes an integer 'T' the no of test cases and the next line denotes 'N' the no of nodes of linked list . Then the line after that contains N space separated integers denoting the values of the nodes of the linked list.
*/

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*start;

void insert();
void display(Node *head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      start=NULL;
      insert();
      display(start);
      cout<<endl;
    }
    return 0;

}


 void insert()
 {
     int n,value;
     cin>>n;
     struct Node *temp;
     for(int i=0;i<n;i++)
     {
         cin>>value;
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }

/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/
void display(Node *head)
{
  //your code goes here
   Node *temp;
   temp=head;
  while(temp != NULL)
  {
      cout << temp->data << " ";
      temp = temp->next;
  }
}