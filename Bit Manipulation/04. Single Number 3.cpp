class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
			long XOR = 0;
			for(int i = 0; i < nums.size(); i++) {
				XOR = XOR ^ nums[i];
			}

			int right = (XOR & (XOR - 1)) ^ XOR;

			int b1 = 0;
			int b2 = 0;

			for(int i = 0; i < nums.size(); i++) {
				if(nums[i] & right) {
					b1 = b1 ^ nums[i];
				} else {
					b2 = b2 ^ nums[i];
				}
			}

			if(b1 < b2) {
				return { b1, b2 };
			}
			return { b2, b1 };
		}	
};