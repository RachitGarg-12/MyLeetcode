class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n=nums.size(),m=q.size();
        sort(nums.begin(),nums.end());
        vector<int> pref(n);pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            // if(pref[0]>q[i]){ans[i]=0;continue;}
            int ind = lower_bound(pref.begin(),pref.end(),q[i])-pref.begin();
            if(ind==n){ans[i]=n;continue;}
            if(pref[ind]>q[i]){ans[i]=ind;}
            else{ans[i]=ind+1;}
        }
        return ans;
    }
};