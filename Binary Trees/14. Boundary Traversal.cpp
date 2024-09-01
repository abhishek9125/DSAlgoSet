class Solution{
public:

    bool isLeaf(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return false;
    }

    void addLeftBoundary(TreeNode* node, vector<int>& result) {
        TreeNode* current = node->left;
        while(current) {
            if(!isLeaf(current)) {
                result.push_back(current->data);
            }

            if(current->left) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }

    void addRightBoundary(TreeNode* node, vector<int>& result) {
        vector<int> temp;
        TreeNode* current = node->right;
        while(current) {
            if(!isLeaf(current)) {
                temp.push_back(current->data);
            }

            if(current->right) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        for(int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* node, vector<int>& result) {
        if(isLeaf(node)) {
            result.push_back(node->data);
            return;
        }

        if(node->left) {
            addLeaves(node->left, result);
        }

        if(node->right) {
            addLeaves(node->right, result);
        }
    }

    vector <int> boundary(TreeNode* root){
    	//your code goes here
        vector<int> result;
        if(root == NULL) return result;
        if(!isLeaf(root)) result.push_back(root->data);

        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);

        return result;
    }
};