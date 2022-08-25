class Solution {
public:
    bool canConstruct(string a, string b) {
        map<int,int> m;
        for(auto i:a){m[i]++;}
        for(auto i:b){if(m[i]) m[i]--;}
        for(auto i:m){if(i.second!=0) return false;}
        return true;
    }
};