class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a=0,b=0;int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#'){if(a)a--;}
            else{s[a]=s[i];a++;}
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#'){if(b)b--;}
            else{t[b]=t[i];b++;}
        }
        if(a!=b)return false;
        for(int i=0;i<a;i++){if(s[i]!=t[i])return false;}
        return true;
    }
};