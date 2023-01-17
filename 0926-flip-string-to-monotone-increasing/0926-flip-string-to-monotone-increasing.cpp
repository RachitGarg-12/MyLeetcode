class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> z(n),o(n);
        z[n-1]=(s[n-1]=='0')?1:0;
        o[0]=(s[0]=='1')?1:0;
        for(int i=n-2;i>=0;i--){
            z[i]=z[i+1];
            if(s[i]=='0'){z[i]++;}
        }
        for(int i=1;i<n;i++){
            o[i]=o[i-1];
            if(s[i]=='1'){o[i]++;}
        }
        int flip=0;
        int ans=n;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(o[i]==0){continue;}
                if(o[i]>0){flip++;}
                
            }
            if(flip>o[i]){flip=o[i];}
        }
        
        return flip;
    }
};