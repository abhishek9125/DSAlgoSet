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

		void postorder(TreeNode* root, vector<int>& result) {
			if(root == NULL) return;

			postorder(root->left, result);
			postorder(root->right, result);
			result.push_back(root->data);
		}

		vector<int> postorder(TreeNode* root){
	        //your code goes here
			vector<int> result;
			postorder(root, result);
			return result;
		}
};