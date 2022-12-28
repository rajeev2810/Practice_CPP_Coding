// C/C++ program to print reverse of linked list
// without extra space and without modifications.
#include<iostream>
#include<memory>

using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};


class LinkedList {
/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
public:
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
	int count = 0; // Initialize count
	struct Node* current = head; // Initialize current
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

/* Takes head pointer of the linked list and index
	as arguments and return data at index*/
int getNth(struct Node* head, int n)
{
	struct Node* curr = head;
	for (int i=0; i<n-1 && curr != NULL; i++)
	    curr = curr->next;
	
    return curr->data;
}

void printReverse(Node *head)
{
	// Count nodes
	int n = getCount(head);

	for (int i=n; i>=1; i--)
		cout << getNth(head, i) << endl;
}
};

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

    LinkedList linkedList;
	/* Use push() to construct below list
	1->2->3->4->5 */
	linkedList.push(&head, 5);
	linkedList.push(&head, 4);
	linkedList.push(&head, 3);
	linkedList.push(&head, 2);
	linkedList.push(&head, 1);

	linkedList.printReverse(head);

	return 0;
}
