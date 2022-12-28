// ConstructBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 **/
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    set<TreeNode*> s;
    stack<TreeNode*> st;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& p, vector<int>& i, int start, int end, unordered_map<int, int>& m) {
        
        if (end < start)
            return nullptr;

        if (p.size() == preIndex)
            return nullptr;

        int curr = p[preIndex++];
        TreeNode* tNode = new TreeNode(curr);

        if (start == end)
            return tNode;

        int inIndex = m[curr];

        tNode->left = buildTree(i, p, start, inIndex - 1, m);
        tNode->right = buildTree(i, p, inIndex + 1, end, m);

        return tNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        int len = inorder.size();
        /*
        unordered_map<int, int> mp;

        for (int i = 0; i < len; i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, len - 1, mp);
        */
        TreeNode* root = NULL;
        for (int pre = 0, in = 0; pre < len;)
        {
            TreeNode* node = NULL;
            do
            {
                node = new TreeNode(preorder[pre]);
                if (root == NULL)
                {
                    root = node;
                }
                if (st.size() > 0)
                {
                    if (s.find(st.top()) != s.end())
                    {
                        s.erase(st.top());
                        st.top()->right = node;
                        st.pop();
                    }
                    else
                    {
                        st.top()->left = node;
                    }
                }
                st.push(node);
            } while (preorder[pre++] != inorder[in] && pre < len);

            node = NULL;
            while (st.size() > 0 && in < len &&
                st.top()->val == inorder[in])
            {
                node = st.top();
                st.pop();
                in++;
            }

            if (node != NULL)
            {
                s.insert(node);
                st.push(node);
            }
        }

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> pre = { 3,9,20,15,7 };
    vector<int> in = { 9,3,15,20,7 };
    s.buildTree(pre, in);
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
