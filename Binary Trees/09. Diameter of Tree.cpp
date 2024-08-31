// Optimised
class Solution {
public:

    class Pair {
        public:
            int height;
            int diameter;
    };

    Pair fastDiameter(TreeNode* root) {
        Pair p;
        if(root == nullptr) {
            p.height = 0;
            p.diameter = 0;
            return p;
        }

        Pair left = fastDiameter(root->left);
        Pair right = fastDiameter(root->right);

        p.height = max(left.height, right.height) + 1;
        p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Pair p = fastDiameter(root);
        return p.diameter;
    }
};

// Brute
class Solution {
public:

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        //your code goes here
        if(root == nullptr) return 0;
        int op1 = height(root->left) + height(root->right);
        int op2 = diameterOfBinaryTree(root->left);
        int op3 = diameterOfBinaryTree(root->right);
        return max(op1, max(op2, op3));
    }
};