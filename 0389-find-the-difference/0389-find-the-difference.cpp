class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(auto i:s){m[i]++;}
        for(auto i:t){
            if(m[i]==0){return i;}
            m[i]--;
        }
        return 'a';
    }
};