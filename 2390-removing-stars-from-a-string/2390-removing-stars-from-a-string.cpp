class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(ans.size()>0){ans.pop_back();}
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};