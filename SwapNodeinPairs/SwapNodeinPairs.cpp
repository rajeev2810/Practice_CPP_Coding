// SwapNodeinPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int data{};
    ListNode* next{ nullptr };
public:
    ListNode() : data(0), next(nullptr) {

    }
    ListNode(int data) : data(data), next(nullptr) {

    }
    ListNode(int data, ListNode* next) : data(data), next(next) {

    }
};

class Solution {
public:

	// function to create and return a Node
	void createNode(ListNode** root, int data)
	{
		ListNode* node = new ListNode(data);
		ListNode* ptr;
		if (*root == NULL) {
			*root = node;
		}
		else {
			ptr = *root;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = node;
		}
	}

	ListNode* swapNodes(ListNode* root) {

		if (root == nullptr || root->next == nullptr)
			return root;

		ListNode* prev = root;
		ListNode* curr = root->next;
		root = curr;

		while (true) {
			ListNode* next = curr->next;
			curr->next = prev;
			if (next == nullptr || next->next == nullptr) {
				prev->next = next;
				break;
			}
			prev->next = next->next;
			prev = next;
			curr = prev->next;
		}
		return root;
	}

	void printListNode(ListNode* head) {
		while (head != NULL) {
			cout << head->data << "\t";
			head = head->next;
		}
		cout << endl;
	}
};

int main()
{
	Solution s;
	ListNode* head = NULL;
	vector<int> arr = { 3, 4, 6, 9,10, 12 };
	for (auto v : arr) {
		s.createNode(&head, v);
	}
	s.printListNode(head);
	ListNode* res = s.swapNodes(head);
	s.printListNode(res);    
}
