/*Clone a linked list with next and random pointer
You are given a Singly Linked List with N nodes where each node next pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1
Input:
First line of input contains number of testcases T. For each testcase, first line of input contains two integers N and M. Next line of input contains values of N nodes of the linked list and last line contains M pairs denoting arbitrary connecting  nodes, for which each ith node is connected to any jth node. ( ith->arb = jth ).
NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Output:
For each testcase, clone the given linked list.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Example:
Input:
2           
4 2                                       
1 2 3 4                             
1 2 2 4
4 3
1 3 5 9
1 1 3 4
Output:
1
1

Explanation:
Testcase 1: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. The fourth line gives the information about arbitrary pointers. The first node arbit pointer is set to node 2.  The second node arbit pointer is set to node 4.
Testcase 2: In the given testcase , applying the method as stated in the abpve testcase , the output will be 1.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

Node *copyList(Node *head);

void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res, Node *cloned_addr,
                Node *generated_addr) {

    if (generated_addr == cloned_addr) return false;

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data) return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    /*reading input stuff*/
    cin >> T;

    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
            }
            Node *tempB = head;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
            }

            // when both a is greater than N
            if (a <= n) tempA->arb = tempB;
        }
        /*read finished*/

        generated_addr = head;
        Node *res = copyList(head);

        Node *cloned_addr = res;

        cout << validation(head, res, cloned_addr, generated_addr) << endl;
    }

    return 0;
}

/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    // Your code here
     Node* curr = head, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new Node(curr->data); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = head; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->arb = curr->arb ?  
                                 curr->arb->next : curr->arb; 
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    Node* original = head, *copy = head->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;
}