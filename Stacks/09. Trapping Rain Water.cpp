// Optimal Solution
class Solution
{
public:
    int trap(vector<int> &height){
        
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;

        int total = 0;

        while(left < right) {
            if(height[left] <= height[right]) {
                if(leftMax > height[left]) {
                    total = total + leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            } else {
                if(rightMax > height[right]) {
                    total = total + rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }

        return total;

    }
};

// Brute Force
class Solution
{
public:
    int trap(vector<int> &height){

        int n = height.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
    
        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int total = 0;
        
        for(int i = 0; i < n; i++) {
            int h = min(left[i], right[i]);
            if(h > height[i]) {
                total += h - height[i];
            }
        }

        return total;
    }
};