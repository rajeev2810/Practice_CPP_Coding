#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    TreeNode* right;
    TreeNode* left;
    int val;

    TreeNode(int val) : val(val), right(nullptr), left(nullptr)
    {

    }
    TreeNode(int val, TreeNode*left, TreeNode* right) : val(val), left(left), right(right) {

    }
};

class Solution {
public:
    TreeNode* connect(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (size(q)) {
            TreeNode* rightNode = nullptr;                    // set rightNode to null initially
            for (size_t i = size(q); i; i--) {                // traversing each level
                auto cur = q.front(); q.pop();            // pop a node from current level and,
                cur->right = rightNode;                  // set its next pointer to rightNode
                rightNode = cur;                          // update rightNode as cur for next iteration
                if (cur->right)                          // if a child exists
                    q.push(cur->right),                 // IMP: push right first to do right-to-left BFS
                    q.push(cur->left);                  // then push left
            }
        }
        return root;
    }
};

int main()
{
    return 0;
}