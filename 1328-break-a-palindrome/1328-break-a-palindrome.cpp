class Solution {
public:
    string breakPalindrome(string p) {
        int n=p.size();
        if(n==1){return "";}
        string ans="";
        bool b=false;
        for(int i=0;i<n;i++){
            if(p[i]!='a'){
                if(n%2 && i==n/2){continue;}
                p[i]='a';b=true;break;}
        }
        if(b==true){return p;}
        p[n-1]='b';
        return p;
    }
};