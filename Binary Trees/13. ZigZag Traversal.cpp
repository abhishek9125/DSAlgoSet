class Solution {
public:

    void reverse(vector<int>& output) {
        int i = 0;
        int j = output.size() - 1;

        while(i < j) {
            int temp = output[i];
            output[i] = output[j];
            output[j] = temp;
            i++;
            j--;
        }
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        vector<int> output;

        q.push(root);
        q.push(nullptr);

        bool isReverse = false;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front == nullptr) {
                if(isReverse) {
                    reverse(output);
                }
                result.push_back(output);
                output.clear();
                if(!q.empty()) {
                    q.push(nullptr);
                }

                isReverse = !isReverse;

            } else {
                output.push_back(front->data);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }

        return result;
    }
};