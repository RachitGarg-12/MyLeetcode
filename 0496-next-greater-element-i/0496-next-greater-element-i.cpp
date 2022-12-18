class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;int n=nums2.size();
        stack<int> s;s.push(nums2[n-1]);
        m[nums2[n-1]]=-1;
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                  s.pop();
            }
            if(s.empty()){m[nums2[i]]=-1;}
            else{m[nums2[i]]=s.top();}
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i:nums1){ans.push_back(m[i]);}
        return ans;
    }
};