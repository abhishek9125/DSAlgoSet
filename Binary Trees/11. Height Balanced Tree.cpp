// Optimised
class Solution{
public:
    
    class Pair {
        public:
            int height;
            bool isBalanced;
    };

    Pair isBalancedOptimised(TreeNode* root) {
        Pair p;
        if(root == nullptr) {
            p.height = 0;
            p.isBalanced = true;
            return p;
        }

        Pair left = isBalancedOptimised(root->left);
        Pair right = isBalancedOptimised(root->right);

        p.height = max(left.height, right.height) + 1;
        p.isBalanced = abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced;
        return p;
    }

    bool isBalanced(TreeNode *root){
        Pair p = isBalancedOptimised(root);
        return p.isBalanced;
    }
};

// Brute
class Solution{
public:
    
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode *root){
        if(root == nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};