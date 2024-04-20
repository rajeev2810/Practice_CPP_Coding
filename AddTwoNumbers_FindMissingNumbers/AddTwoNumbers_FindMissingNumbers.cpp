/**
 * Definition for singly-linked list.
 **/

#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    void insertNode(ListNode** root, int data)
    {
        ListNode* newNode = new ListNode(data);
        if (*root == NULL)
            *root = newNode;
        else
        {
            ListNode* current = *root;
            while (current->next != nullptr)
            {
                current = current->next;                
            }
            current->next = newNode;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* currNode = head;
        int carry{};
        while (l1 != nullptr || l2 != nullptr)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            //carry = sum / 10;
            currNode->next = new ListNode(sum);
            currNode = currNode->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        /*if (carry > 0) {
            currNode->next = new ListNode(carry);
        }
        */
        return head->next;
    }

    void printList(ListNode* root)
    {
        while (root != NULL) {
            cout << root->val << " ";
            root = root->next;
        }
    }

    int findMissingNumber(vector<int> arr) {
        const int n = size(arr) + 1;
        //x1 represents XOR of all values from 1 to n
        //find sum of all numbers from 1 to n
        int x1 = 1;
        for (int i = 2; i <= n; i++) {
            x1 = x1 ^ i;
        }
        //x2 represents XOR of all values in arr
        int x2 = arr[0];
        for (int i = 1; i < n - 1; i++) {
            x2 = x2 ^ arr[i];
        }
        //missing number is the xor of x1 and x2
        return x1 ^ x2;
    }
};

int main()
{
    Solution s;
    ListNode* node1 = NULL;
    ListNode* node2 = NULL;

    vector<int> input1{ 1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20 };
    vector<int> input2{ 1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20 };

    cout << s.findMissingNumber(input1) << endl;
    for (auto& v : input1)
    {
        s.insertNode(&node1, v);
    }
    for (auto& v : input2)
    {
        s.insertNode(&node2, v);
    }
    s.printList(node1);
    cout << endl;
    s.printList(node2);
    ListNode* addedList = s.addTwoNumbers(node1, node2);
    cout << endl;
    s.printList(addedList);

    delete(node1);
    delete(node2);
    delete(addedList);

    return 0;
}
