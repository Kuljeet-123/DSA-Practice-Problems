/*QuickSort on Doubly Linked List
Sort the given doubly linked list using quicksort. Just complete the partition function using quicksort technique try to solve it in O(1) space.

Input:
In this problem, method takes two argument: the node1 and node2. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Return p from function.

User Task:
The task is to complete the function 

Constraints:
1 <= T <= 100
1 <= N <= 200

Example:
Input:
2
3
4 2 9
4
1 4 9 2

Output:
2 4 9
1 2 4 9
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

void swap(int* a, int* b )
{   
    int t = *a;
    *a = *b;
    *b = t;
}

Node* partition(Node *l, Node *h);

void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

 
int main()
{
    int t,x,n,i;
    scanf("%d",&t);
    while(t--)
    {
        /* Start with the empty list */
        struct Node *p,*temp,*head = NULL;
        scanf("%d",&n);
        scanf("%d",&x);
        head=new Node(x);
        p=head;
        for(i=0;i<n-1;i++){
            scanf("%d",&x);
            /* Let us create the doubly linked list 10<->8<->4<->2 */
        	temp=new Node(x);
        	p->next=temp;
        	temp->prev=p;
            p=p->next;
        }
    
    //printList(head); 
    /* delete Nodes from the doubly linked list */
	
    quickSort(head);
  
    /* Modified linked list will be NULL<-8->NULL */
    printList(head);           
    while(head->next!=NULL)
    {
	  temp=head;
	  head=head->next;
	  free(temp);
	}
	  free(head);
	}
    return 0;
}

/* a Node of the doubly linked list */

/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/



Node* partition(Node *l, Node *h){
    //Your code goes here
     int x = h->data;  
  
    // similar to i = l-1 for array implementation  
    Node *i = l->prev;  
  
    // Similar to "for (int j = l; j <= h- 1; j++)"  
    for (Node *j = l; j != h; j = j->next)  
    {  
        if (j->data <= x)  
        {  
            // Similar to i++ for array  
            i = (i == NULL)? l : i->next;  
  
            swap(&(i->data), &(j->data));  
        }  
    }  
    i = (i == NULL)? l : i->next; // Similar to i++  
    swap(&(i->data), &(h->data));  
    return i;  

}