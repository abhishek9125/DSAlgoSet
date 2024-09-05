class Solution{
    public:
    
    void heapify(vector<int>& ans, int index) {
        int n = ans.size();
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        
        if(left < n && ans[largest] < ans[left]) {
            largest = left;
        }
        
        if(right < n && ans[largest] < ans[right]) {
            largest = right;
        }
        
        if(largest != index) {
            swap(ans[largest], ans[index]);
            heapify(ans, largest);
        }
        
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(auto i: a) {
            ans.push_back(i);
        }
        
        for(auto i: b) {
            ans.push_back(i);
        }
        
        for(int i = (ans.size()/2) - 1; i>= 0; i--) {
            heapify(ans, i);
        }
        
        return ans;
    }
};