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

		void preorder(TreeNode* node, vector<int>& result) {
			if(node == nullptr) {
				return;
			}

			result.push_back(node->data);
			preorder(node->left, result);
			preorder(node->right, result);
		}

		vector<int> preorder(TreeNode* root){
	       //your code goes here
		    vector<int> result;
			preorder(root, result);
		    return result;
		}
};