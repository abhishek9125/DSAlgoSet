// Optimal
class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        if(n == 0) return 1;
        if(n < 0) {
            x = 1 / x;
            n = n*-1;
        }
        if(n%2 == 0) return myPow(x*x, n/2);
        return x * myPow(x, n - 1);
    }
};

// Brute
class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here
        if(n == 0) return 1;
        if(n < 0) {
            x = 1 / x;
            n = n*-1;
        }
        return x * myPow(x, n - 1);
    }
};