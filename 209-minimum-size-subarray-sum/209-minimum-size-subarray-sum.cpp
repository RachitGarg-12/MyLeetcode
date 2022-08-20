 class Solution {
public:
		int minSubArrayLen(int target, vector<int>& nums) {

		int i = 0, j = 0;
		int sum = 0;
		int n = nums.size();

		for(auto it:nums) sum += it;
		if(sum < target) return 0;

		sum = 0;
		int ans = INT_MAX;

		while(j < n){
			sum += nums[j];
			while(sum >= target){
                int len=j-i+1;
				ans = min(ans,len);
				sum -= nums[i];
				i++;
			}
			j++;
		}

		return ans;  
        }
};