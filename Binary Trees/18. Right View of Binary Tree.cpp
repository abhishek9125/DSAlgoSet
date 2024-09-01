/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //your code goes here
        vector<int> result;
        if(root == nullptr) return result;
        map<int, int> nodes;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });

        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second;

            if(nodes.find(level) == nodes.end()) {
                nodes[level] = node->data;
            }

            if(node->right) q.push({ node->right, level + 1 });
            if(node->left) q.push({ node->left, level + 1 });

        }

        for(auto i: nodes) {
            result.push_back(i.second);
        }

        return result;
    }
};