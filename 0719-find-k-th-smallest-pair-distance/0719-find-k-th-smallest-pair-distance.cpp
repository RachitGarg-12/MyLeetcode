class Solution {
public:
    int countPairs(vector<int>& nums, int mid, int n){
        int pairs=0,i=0;
        for(int j=1;j<n;j++){
            while(i<j && nums[j]-nums[i]>mid){i++;}
            pairs+=j-i;
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0],ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countPairs(nums,mid,n)<k){
                // ans=mid;
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
        
    }
};