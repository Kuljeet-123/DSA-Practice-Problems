/*Intersection Point in Y Shapped Linked Lists
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.
Note: Expected time complexity is O(m + n) where m and n are lengths of two linked lists.

Input:
First line of input is the number of test cases T. Every test case has four lines. First line of every test case contains three numbers, x (number of nodes before merge point in 1st list), y (number of nodes before merge point in 2nd list) and z (number of nodes after merge point). Next three lines contain x, y and z values.

Output:
Print the data of the node in the linked list where two linked lists intersects.

Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= value <= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 2
10 20
30 40 50
10 20
Output:
5
10

Explanation:
Testcase 1: The point of intersection of two linked list is 5, means both of them get linked (intersects) with each other at node whose value is 5.
Testcase 2: The point of intersection of two linked list is 10. Hence, output is 10.
*/

#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int getCount(Node* head) 
{ 
    Node* current = head; 
  
    // Counter to store count of nodes 
    int count = 0; 
  
    // Iterate till NULL 
    while (current != NULL) { 
  
        // Increase the counter 
        count++; 
  
        // Move the Node ahead 
        current = current->next; 
    } 
  
    return count; 
} 

int _getIntesectionNode(int d, Node* head1, Node* head2) 
{ 
    // Stand at the starting of the bigger list 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    // Move the pointer forward 
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    // Move both pointers of both list till they 
    // intersect with each other 
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        // Move both the pointers forward 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
} 

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    // If first is greater 
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntesectionNode(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntesectionNode(d, head2, head1); 
    } 
}

