class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n=s.size();
        map<string,vector<string>> m;
        for(int i=0;i<n;i++){
            string t=s[i];sort(t.begin(),t.end());
            m[t].push_back(s[i]);
        }
        vector<vector<string>> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};