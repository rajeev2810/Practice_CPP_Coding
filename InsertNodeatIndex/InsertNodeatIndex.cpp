// InsertNodeatIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() :val(0), next(nullptr) {
	};
	ListNode(int val) : val(val), next(nullptr) {
	};
	ListNode(int val, ListNode* next) : val(val), next(next) {
	};
};

class LinkedList
{
private:
	size_t size{};
public:
	
	// function to create and return a Node
	void createNode(ListNode** root, int data)
	{
		ListNode* node = new ListNode(data);
		ListNode* ptr;
		if (*root == NULL) {
			*root = node;
			size = 1;
		}
		else {
			ptr = *root;
			while (ptr->next != NULL) {
				ptr = ptr->next;
				size++;
			}
			ptr->next = node;
		}
	}

	void insertNode(ListNode** curr, int index, int data) {
		if (index < 1 || index > size + 1)
			return;
		else {
			while (index--) {
				if (index == 0) {
					ListNode* temp = new ListNode(data); 
					temp->next = (*curr)->next;
					(*curr)->next = temp;
				}
				else {
					curr = &(*curr)->next;
				}
			}
			size++;
		}
	}

	void printListNode(ListNode* head) {
		while (head != NULL) {
			cout << " " << head->val;
			head = head->next;
		}
		cout << endl;
	}
};

int main()
{
	LinkedList list;
	ListNode* head = NULL;
	vector<int> arr = { 3, 4, 6, 9,10 };
	for (auto v : arr) {
		list.createNode(&head, v);
	}

	cout << "Linked list before insertion: ";
	list.printListNode(head);
	list.insertNode(&head, 3, 12);
	cout << "Linked list after insertion of 12 at position 3: ";
	list.printListNode(head);

}
