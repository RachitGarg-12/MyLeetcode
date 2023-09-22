class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){return true;}
        int ind=0,n=s.size();
        for(auto i:t){
            if(s[ind]==i){
                ind++;
            }
            if(ind==n){return true;}
        }
        return false;
    }
};