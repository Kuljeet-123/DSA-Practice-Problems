/*Occurence of an integer in a Linked List
Given a singly linked list and a key, count number of occurrences of given key in linked list. For example, if given linked list is 1->2->1->2->1->3->1 and given key is 1, then output should be 4.

Input:
You have to complete the method which takes two argument: the head of the linked list and int k. You should not read any input from stdin/console. The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. There are multiple test cases. For each test case, this method will be called individually.

Output:
You have to count a number of occurrences of given key in linked list and return the count value.

User Task:
The task is to complete the function count() which counts the number of occurrences of given element.

Example:
Input:
1
8
1 2 2 4 5 6 7 8
2

Output:
2

Explanation:
Testcase 1: 2 is occurring twice in the given linked list.
*/


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int count(struct node* head, int search_for);
/* Link list node */
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;

void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new node(value);
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= new node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     value=count(head, k);
     printf("%d\n",value);
     }
     return(0);
}
/*
  Return the no. of times search_for value is there in a linked list.
  The input list will have at least one element  

  Node is defined as 
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
int count(struct node* head, int search_for)
{
//add your code here
  if (head == NULL) 
        return 0; 
    if (head->data == search_for) 
        return 1 + count(head->next, search_for); 
    return count(head->next, search_for); 
}