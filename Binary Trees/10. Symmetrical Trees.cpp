/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:

    bool symmetry(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->data != q->data) return false;
        return symmetry(p->left, q->right) && symmetry(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        //your code goes here
        if(root == nullptr) return true;
        return symmetry(root->left, root->right);
    }
};