/*Add two numbers represented by linked lists
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the first linked list and next line contains N elements of the linked list. Again, the next line contains M, and the following line contains M elements of the linked list.

Output:
Output the resultant linked list.

User Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.
Note:
The linked list has been constructed in the reverse order of the number. That is if the number is given is 123 then the linked list representing it is 3 -> 2 -> 1.
Hence, the resultant number to be printed will be in reverse order(rightmost digit as head and followed by digits to its left).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7
Output:
0 9 3 
0 7

Explanation:
Testcase 1: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (0 9 3).
Testcase 2: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (0 7).
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    // Code here
     Node* res = NULL; // res is head node of the resultant list  
    Node *temp, *prev = NULL;  
    int carry = 0, sum;  
  
    while (first != NULL || second != NULL) //while both lists exist  
    {  
        sum = carry + (first? first->data: 0) + 
                      (second? second->data: 0);  
  
        carry = (sum >= 10)? 1 : 0;  
  
        sum = sum % 10;  
  
        temp = new Node(sum);  
  
        if(res == NULL)  
            res = temp;  
              
        else  
            prev->next = temp;  
  
        prev = temp;  
  
        if (first) first = first->next;  
        if (second) second = second->next;  
    }  
  
    if (carry > 0)  
    temp->next = new Node(carry);  

    return res;  
}