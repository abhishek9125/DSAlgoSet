class Solution{   
public:    
    int minBitsFlip(int start, int goal) { 
        //Your code goes here
        int num = start ^ goal;
        int count = 0;

        // for(int i = 0; i < 32; i++) {
        //     count += (num&1);
        //     num = num >> 1;
        // }

        while(num != 0) {
            num = (num & num - 1);
            count++;
        }

        return count;
    }
};