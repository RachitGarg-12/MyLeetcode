class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pre(n,0);
        for(int i=1;i<n;i++){
            if((nums[i]%2==0 && nums[i-1]%2==0) || (nums[i]%2==1 && nums[i-1]%2==1)){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1];
            }
        }
        vector<bool> ans;
        for(auto i:queries){
            int l=i[0],r=i[1];
            int cur=pre[r]-(l>0?pre[l]:0);
            ans.push_back(cur==0);
        }
        return ans;
    }
};