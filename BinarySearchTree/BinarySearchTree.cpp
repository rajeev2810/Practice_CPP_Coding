// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {

    }
    TreeNode() : data(0), left(nullptr), right(nullptr) {

    }
    TreeNode(int data, TreeNode* left, TreeNode* right) : data(data), left(left), right(right) {

    }
};

class BST {
private:
    TreeNode* root;
public:
    BST() : root(nullptr) {

    }
    TreeNode* getRoot() {
        return root;
    }
    void iterativeInsert(int key) {
        TreeNode* temp = root;
        TreeNode* p;
        TreeNode* r = nullptr;

        if (root == nullptr) {
            p = new TreeNode;
            p->data = key;
            p->left = nullptr;
            p->right = nullptr;
            root = p;
            return;
        }
        while (temp != nullptr) {
            r = temp;
            if (key < temp->data) {
                temp = temp->left;
            }
            else if (key > temp->data) {
                temp = temp->right;
            }
            else {
                return;
            }
        }
        p = new TreeNode;
        p->data = key;
        p->left = nullptr;
        p->right = nullptr;

        if (key < r->data) {
            r->left = p;
        }
        else {
            r->right = p;
        }
    }
    void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->data << "\t" << flush;
            inorderTraversal(root->right);
        }
    }
    TreeNode* iterativeSearch(int key) {
        TreeNode* temp = root;
        while (temp != nullptr) {
            if (key < temp->data) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return temp;
    }
    TreeNode* recursiveSearch(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key == root->data) {
            return root;
        }
        else if (key < root->data) {
            return recursiveSearch(root->left, key);
        }
        else {
            return recursiveSearch(root->right, key);
        }
    }
    TreeNode* recursiveInsert(TreeNode* root, int key) {
        TreeNode* temp = nullptr;
        if (root == nullptr) {
            temp = new TreeNode;
            temp->data = key;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }
        if (key < root->data) {
            root->left = recursiveInsert(root->left, key);
        }
        else if (key > root->data) {
            root->right = recursiveInsert(root->right, key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

    }
    int height(TreeNode* root) {
        int leftcount, rightcount;
        if (root == nullptr) {
            return 0;
        }
        leftcount = height(root->left);
        rightcount = height(root->right);

        return leftcount > rightcount ? leftcount + 1 : rightcount + 1;
    }
    TreeNode* inPre(TreeNode* root) {
        while (root && root->right) {
            root = root->right;
        }
        return root;
    }
    TreeNode* inSucc(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }
};


int main()
{
    BST bst;
    bst.iterativeInsert(10);
    bst.iterativeInsert(11);
    bst.iterativeInsert(12);
    bst.iterativeInsert(9);
    bst.iterativeInsert(8);
    TreeNode* tree = bst.getRoot();
    bst.recursiveInsert(tree, 15);
    bst.recursiveInsert(tree, 16);
    bst.recursiveInsert(tree, 20);
    bst.recursiveInsert(tree, 1);
    bst.recursiveInsert(tree, 3);
    tree = bst.getRoot();
    bst.inorderTraversal(tree);
}