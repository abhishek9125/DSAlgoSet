/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:

		void inorder(TreeNode* root, vector<int>& result) {
			if(root == NULL) return;

			inorder(root->left, result);
			result.push_back(root->data);
			inorder(root->right, result);
		}

		vector<int> inorder(TreeNode* root){
	        //your code goes here
			vector<int> result;
			inorder(root, result);
			return result;
		}
};