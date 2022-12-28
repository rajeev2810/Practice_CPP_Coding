#include <iostream>

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
    ListNode* mergeNodes(ListNode* head) {
        
        if (head->val == 0)
            head = head->next;
        
        ListNode* newNode = head;
        ListNode* temp = head;
        
        int sum = 0;
        while(temp)
        {
         
            // loop to sum the data of nodes till
            // it encounters 0
            
            if(temp->val != 0)
            {
                sum += temp->val;
                temp = temp->next;
            }

            // If we encounters 0, we need
            // to update next pointers
            else
            {
                newNode->val = sum;
                newNode->next = temp->next;
                temp = temp->next;
                newNode = temp;
                sum = 0;
            }
        }      
        return head;        
    }

    ListNode *getNode(int val)
    {
        ListNode *temp;
        temp = new ListNode(val, nullptr);
        return temp;
    }
 
};

int main()
{
     ListNode *head;    
    Solution s;
    head = s.getNode(0);
    head->next = s.getNode(3);
    head->next->next = s.getNode(1);
    head->next->next->next = s.getNode(0);
    head->next->next->next->next = s.getNode(4);
    head->next->next->next->next->next = s.getNode(5);
    head->next->next->next->next->next->next = s.getNode(2);
    head->next->next->next->next->next->next->next = s.getNode(0);   
    ListNode* newNode = s.mergeNodes(head);
    
    while (newNode != nullptr)
    {
        cout << newNode->val << endl;
        newNode = newNode->next;
    }
}