class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size(),m=s.size();
        if(n>m)return {};
        vector<int> ans;
        vector<int> pfreq(26),sfreq(26);
        for(auto i:p){pfreq[i-'a']++;}
        for(int i=0;i<n;i++){sfreq[s[i]-'a']++;}
        if(pfreq==sfreq){ans.push_back(0);}
 
        for(int i=1;i<=m-n;i++){
            sfreq[s[i-1]-'a']--;sfreq[s[i+n-1]-'a']++;
            if(sfreq==pfreq){ans.push_back(i);}
        }
        return ans;
    }
};