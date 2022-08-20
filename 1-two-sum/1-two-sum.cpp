class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n=a.size();vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int left=target-a[i];
           if(m.find(left)!=m.end()){ans.push_back(m[left]);ans.push_back(i);break;} 
             m[a[i]]=i;
        }
        return ans;
    }
};