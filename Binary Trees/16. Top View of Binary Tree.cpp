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
    vector<int> topView(TreeNode *root){
        //your code goes here
        vector<int> result;
        if(root == nullptr) return result;
        map<int, int> nodes;
        queue<pair<TreeNode*,int>> q;
        q.push({ root, 0 });

        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int hd = p.second;

            if(nodes.find(hd) == nodes.end()) {
                nodes[hd] = node->data;
            }

            if(node->left) q.push({ node->left, hd - 1 });
            if(node->right) q.push({ node->right, hd + 1 });
        }

        for(auto i : nodes) {
            result.push_back(i.second);
        }

        return result;
    }
};