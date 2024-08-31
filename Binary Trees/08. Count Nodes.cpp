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
    int countNodes(TreeNode* root) { 
        //your code goes here
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};