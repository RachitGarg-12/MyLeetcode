class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        vector<int> vis(26,0);
        for(auto i:s){freq[i]++;}
        string ans="";
        for(auto i:s){
            freq[i]--;
            if(vis[i-'a']){continue;}
            while(ans.size()>0 && i<ans.back() && freq[ans.back()]){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans+=i;
            vis[i-'a']=1;
        }
        return ans;
    }
};