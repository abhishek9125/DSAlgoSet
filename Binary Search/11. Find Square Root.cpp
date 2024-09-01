class Solution {
public:
    long long floorSqrt(long long n)  {
        if(n == 0) return 0;

        long long start = 1;
        long long end = n;
        long long ans;

        while(start <= end) {
            long long mid = start + (end - start) / 2;
            if(mid*mid <= n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};