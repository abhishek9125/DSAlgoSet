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
    vector<vector<int> > verticalTraversal(TreeNode* root) {
    	//your code goes here
        vector<vector<int>> result;
        if(root == nullptr) return result;

        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({ root, { 0, 0 } });

        while(!q.empty()) {
            pair<TreeNode*,pair<int, int>> p = q.front();
            q.pop();
            TreeNode* frontNode = p.first;
            int hd = p.second.first;
            int level = p.second.second;

            nodes[hd][level].push_back(frontNode->data);

            if(frontNode->left) q.push({ frontNode->left, { hd - 1, level + 1 } });
            if(frontNode->right) q.push({ frontNode->right, { hd + 1, level + 1 } });
        }

        for(auto i: nodes) {
            vector<int> column;
            for(auto j: i.second) {
                sort(j.second.begin(), j.second.end());
                column.insert(column.end(), j.second.begin(), j.second.end());
            }
            result.push_back(column);
        }
        return result;
    }
};