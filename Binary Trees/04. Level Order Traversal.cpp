// Recursive

class Solution {
public:

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void printKthLevel(TreeNode* root, int k, vector<int>& output) {
        if(root == NULL) return;
        if(k == 1) {
            output.push_back(root->data);
            return;
        }

        printKthLevel(root->left, k - 1, output);
        printKthLevel(root->right, k - 1, output);
    }

    vector<vector<int> > levelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>> result;
        int H = height(root);
        for(int i = 1; i<= H; i++) {
            vector<int> output;
            printKthLevel(root, i, output);
            result.push_back(output);
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>> result;
        vector<int> output;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                if(!q.empty()) {
                    q.push(NULL);
                }
                result.push_back(output);
                output.clear();
            } else {
                output.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return result;
    }
};