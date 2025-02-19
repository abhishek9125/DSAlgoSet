#include <bits/stdc++.h>
using namespace std;
class Solution{  
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        sort(Jobs.begin(), Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        int n = Jobs.size();

        vector<int> hash(n, -1);

        int count = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = Jobs[i][1] - 1; j >= 0; j--) {
                if (hash[j] == -1) {
                    count++;
                    hash[j] = Jobs[i][0];
                    totalProfit += Jobs[i][2];
                    break;
                }
            }
        }
        return {count,totalProfit};
    } 
};