class Solution {
public:
    string makeGood(string s) {
        int n=s.size();bool b=true;
        while(b){
            b=false;string ans="";
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1){ans+=s[i];break;}
            if((s[i]-'a'==tolower(s[i+1])-'a' && s[i+1]-'a'!=s[i]-'a')
               ||(s[i+1]-'a'==tolower(s[i])-'a' && s[i]-'a'!=s[i+1]-'a')){b=true;i++;continue;}
            ans+=s[i];
        }
            s=ans;
        }
        return s;
    }
};