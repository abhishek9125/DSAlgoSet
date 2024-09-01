class Solution{
	public:

		void findPath(TreeNode* root, vector<int>& path, vector<vector<int>>& result) {
			if(root == nullptr) {
				return;
			}

			path.push_back(root->data);

			if(!root->left && !root->right) {
				result.push_back(path);
			} else {
				findPath(root->left, path, result);
				findPath(root->right, path, result);
			}

			path.pop_back();
		}

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
			vector<vector<int>> result;
			if(root == nullptr) return result;
			vector<int> path;
			findPath(root, path, result);
			return result;
		}
};