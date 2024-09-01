
class Solution {
public:
    int findPeakElement(vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        int mid = start + (end - start) / 2;

        while(start < end) {
            if(arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }

        return start;
    }
};

class Solution {
public:
    int findPeakElement(vector<int> &arr) {

        int n = arr.size();

        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            if (arr[mid] > arr[mid - 1]) low = mid + 1;

            else high = mid - 1;
        }

        return -1; 
    }
};