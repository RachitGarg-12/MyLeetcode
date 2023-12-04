class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> v;
        deque<int> q; 
        int ma=INT_MIN;

        
        int j=0;
        for(int i=0;i<nums.size();i++){ 

            while(!q.empty() && q.back()<nums[i]) q.pop_back();
            
               q.push_back(nums[i]); 

               if(i-j==k-1){ 
              v.push_back(q.front());
              if(nums[j++]==q.front()) q.pop_front();
               }
        }
        return v;        
    }
};