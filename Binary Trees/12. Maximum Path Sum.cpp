class Solution {	
public:

    int findMax(TreeNode* root, int& maxi) {

        if(root == nullptr) return 0;

        int left = max(0, findMax(root->left, maxi));
        int right = max(0, findMax(root->right, maxi));

        maxi = max(maxi, left + right + root->data);

        return max(left, right) + root->data;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findMax(root, maxi);

        return maxi;
    }
};	