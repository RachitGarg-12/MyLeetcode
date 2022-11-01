class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();string ans="";
        if(s[0]==ans){return ans;}
        if(n==1){return s[0];}
        for(int i=0;i<s[0].size();i++){
            char a=s[0][i];bool b=false;
            for(int j=1;j<n;j++){
                if(s[j][i]!=a){b=true;break;}
            }
            if(b){break;}
            else{ans+=a;}
        }
        return ans;
    }
};