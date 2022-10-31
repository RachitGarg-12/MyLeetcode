class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long sc) {
        sort(p.begin(),p.end());int n=s.size();int m=p.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            long long mn=(sc%s[i]==0)?sc/s[i]:(sc/s[i])+1;
            int in=lower_bound(p.begin(),p.end(),mn)-p.begin();
            ans.push_back(m-in);
        }
        return ans;
    }
};