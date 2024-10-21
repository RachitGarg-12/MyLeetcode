class Solution {
public:
    int count(int i,string &s,set<string> mp){
        if(i==s.size())return 0;
        string cur="";
        int ans=0;
        for(int j=i;j<s.size();j++){
            cur+=s[j];
            if(mp.find(cur)==mp.end()){
                mp.insert(cur);
                ans=max(ans,1+count(j+1,s,mp));
                mp.erase(cur);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        set<string> mp;
        return count(0,s,mp);
    }
};