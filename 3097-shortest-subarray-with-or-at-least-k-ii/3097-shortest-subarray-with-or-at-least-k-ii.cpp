class Solution {
    bool checkIfValid(const vector<int>& freq, const int& k)
    {
        int res = 0;
        for(int i=0;i<30;i++)
            res |= (freq[i] ? (1 << i) : 0);
        return res >= k;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        vector<int> freq(30, 0);
        int start = 0, end = 0;
        while (end < nums.size())
        {
            if (nums[end] >= k) return 1;
            // include number at index end
            int i=0,temp=nums[end];
            while(temp && i < 30) { freq[i++] += temp & 1; temp >>= 1; }
            while(start < nums.size() && checkIfValid(freq, k))
            {
                res = min(res, end-start+1);
                // exclude number at index start
                i=0; temp=nums[start];
                while(temp && i < 30) { freq[i++] -= temp & 1; temp >>= 1; }
                start++;
            }
            end++;
        }
        return res == INT_MAX ? -1 : res;
    }
};