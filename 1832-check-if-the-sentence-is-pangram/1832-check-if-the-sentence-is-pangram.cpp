class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> m(26,0);
        for(auto i:sentence){m[i-'a']=1;}
        for(int i=0;i<26;i++){
            if(m[i]==0)return false;
        }
        return true;
    }
};