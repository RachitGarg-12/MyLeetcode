class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        vector<int> ans;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                int cur=nums1[i];
                ans.push_back(cur);
                while(i<n && nums1[i]==cur){i++;}
                while(j<m && nums2[j]==cur){j++;} 
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{i++;}
        }
        return ans;
    }
};