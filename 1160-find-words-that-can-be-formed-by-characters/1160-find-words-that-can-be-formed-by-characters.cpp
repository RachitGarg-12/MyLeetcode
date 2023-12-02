class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int> m;
        for(auto i:chars){m[i]++;}
        for(auto i:words){
            unordered_map<char,int> mp=m;
            bool b=true;
            for(auto j:i){
                if(mp[j]==0){b=false;break;}
                mp[j]--;
            }
            if(b){ans+=(int)i.size();}
        }
        return ans;
    }
};