class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(n!=t.size())return false;
        vector<int> freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(auto i:freq){
            if(i!=0)return false;
        }
        return true;
    }
};