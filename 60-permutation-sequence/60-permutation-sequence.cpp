class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){ s+=to_string(i);}
        for(int i=1;i<k;i++){
        int in;
        for(in=n-2;in>=0;in--){
            if(s[in]<s[in+1]){break;}
        }
        for(int j=n-1;j>in;j--){
            if(s[j]>s[in]){swap(s[j],s[in]);break;}
        }
        reverse(s.begin()+in+1,s.end());   
        }
        return s;
    }
};