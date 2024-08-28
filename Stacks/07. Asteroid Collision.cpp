class Solution{
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        // int n = asteroids.size();
        vector<int> result;
        // stack<int> s;

        // for(int i = 0; i < n; i++) {
            
        //     bool isLeft = arr[i] < 0;
        //     if((!s.empty() && s.top() < 0 && isLeft) || !isLeft) {
        //         s.push(arr[i]);
        //     } else if(isLeft) {
        //         while(s.top() <= arr[i]*-1) {
        //             s.pop();
        //         }
        //     }

        //     if(isLeft && s.empty()) {
        //         s.push(arr[i]);
        //     }

        // }

        // while(!s.empty()) {
        //     result.push_back(s.top());
        //     s.pop();
        // }

        // reverse(result.begin(), result.end());

        return result;
    }
};