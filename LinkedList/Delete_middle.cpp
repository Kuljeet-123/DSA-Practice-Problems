/*Delete Middle of Linked List
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL

Input:
The first line of input contains the number of test cases T. For each test case, there will be two lines of input, first of which contains the number of nodes in the linked list and next line contains elements in the nodes of the linked list.

Output:
For each test case, print the modified linked list in a new line.

User Task:
The task is to complete the function deleteMid() which should delete the middle element from the linked list and return the head of the modified linked list. If the linked list is empty then it should return NULL.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 1000
1 <= N <= 1000
1 <= value <= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
1 2 4 5
2 4 6 5 1

Explanation:
Testcase 1: After deleting the middle of the linked list, 3 will be deleted and the list will be as 1, 2, 4, 5.
*/


#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 

/* Link list Node
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head) {
    // Your Code Here
    if(head == NULL)
       return NULL;
       
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    
    Node* fast=head;
    Node* slow=head;
    Node* prev;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    prev->next = slow->next;
    delete slow;
    
  return head;
}