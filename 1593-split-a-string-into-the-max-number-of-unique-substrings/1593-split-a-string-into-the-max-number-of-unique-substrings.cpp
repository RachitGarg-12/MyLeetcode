class Solution {
public:
    int count(int i,string &s,map<string,bool> mp){
        if(i==s.size())return 0;
        string cur="";
        int ans=0;
        for(int j=i;j<s.size();j++){
            cur+=s[j];
            if(mp.find(cur)==mp.end()){
                mp[cur]=true;
                ans=max(ans,1+count(j+1,s,mp));
                mp.erase(cur);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        map<string,bool> mp;
        return count(0,s,mp);
    }
};