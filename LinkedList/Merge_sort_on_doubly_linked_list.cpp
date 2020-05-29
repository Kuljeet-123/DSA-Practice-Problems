/*Merge Sort on Doubly Linked List
Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Input:
There are be multiple test cases, for each test case function mergeSort() will be called separately. The only input to the function is the pointer/reference to the head of the doubly linked list.

Output:
For each test, print the sorted doubly linked list in both order i.e. in non-decreasing and non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which sorts the doubly linked list. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
8
7 3 5 2 6 4 1 8
5
9 15 0 -1 0
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1

Explanation:
Testcase 1: After sorting the given linked list in both ways, resultant matrix will be as given in the first two line of output, where first line is the output for non-decreasing order and next line is for non-increasing order.
Testcase 2: After sorting the given linked list in both ways, the resultant list will be -1 0 0 9 15 in non-decreasing order and 15 9 0 0 -1 in non-increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends


/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */

Node *split(Node *head)  
{  
    Node *fast = head,*slow = head;  
    while (fast->next && fast->next->next)  
    {  
        fast = fast->next->next;  
        slow = slow->next;  
    }  
    Node *temp = slow->next;  
    slow->next = NULL;  
    return temp;  
}  


Node *merge(Node *first, Node *second)  
{  
    // If first linked list is empty  
    if (!first)  
        return second;  
  
    // If second linked list is empty  
    if (!second)  
        return first;  
  
    // Pick the smaller value  
    if (first->data < second->data)  
    {  
        first->next = merge(first->next,second);  
        first->next->prev = first;  
        first->prev = NULL;  
        return first;  
    }  
    else
    {  
        second->next = merge(first,second->next);  
        second->next->prev = second;  
        second->prev = NULL;  
        return second;  
    }  
}  


// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if (!head || !head->next)  
        return head;  
    Node *second = split(head);  
  
    // Recur for left and right halves  
    head = sortDoubly(head);  
    second = sortDoubly(second);  
  
    // Merge the two sorted halves  
    return merge(head,second); 
}

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}