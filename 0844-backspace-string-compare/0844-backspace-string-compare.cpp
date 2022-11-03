class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(a.size()==0){continue;}
                a.pop_back();continue;}
            a+=s[i];
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#'){
                 if(b.size()==0){continue;}
                b.pop_back();continue;}
            b+=t[i];
        }
        return (a==b);
    }
};