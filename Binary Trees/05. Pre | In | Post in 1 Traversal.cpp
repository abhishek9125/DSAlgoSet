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
		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
			stack<pair<TreeNode*, int>> st;
			vector<int> preorder, inorder, postorder;
			if(root == NULL) return { preorder, inorder, postorder };
			st.push({ root, 1 });

			while(!st.empty()) {
				pair<TreeNode*, int> p = st.top();
				st.pop();

				if(p.second == 1) {
					preorder.push_back(p.first->data);
					p.second++;
					st.push(p);
					if(p.first->left) {
						st.push({ p.first->left, 1 });
					}
				} else if(p.second == 2) {
					inorder.push_back(p.first->data);
					p.second++;
					st.push(p);
					if(p.first->right) {
						st.push({ p.first->right, 1 });
					}
				} else {
					postorder.push_back(p.first->data);
				}

			}

 			return { inorder, preorder, postorder };
		}
};