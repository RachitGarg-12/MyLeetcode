class Solution {
public:
    void rec(int i,string &s,int n,int k){
        if(i==k){return;}
        int in;
        for(in=n-2;in>=0;in--){
            if(s[in]<s[in+1]){break;}
        }
        
        for(int j=n-1;j>in;j--){
            if(s[j]>s[in]){swap(s[j],s[in]);break;}
        }
        reverse(s.begin()+in+1,s.end());
        rec(i+1,s,n,k);
    }
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){ s+=to_string(i);}
        rec(1,s,n,k);
        return s;
    }
};