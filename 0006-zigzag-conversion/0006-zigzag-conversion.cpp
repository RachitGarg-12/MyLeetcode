class Solution {
public:
    string convert(string s, int n) {
        int m=s.length();
        vector<vector<char>> a(n,vector<char>(m,'1'));
        int cur=0;bool b=true;int j=0;
        while(j<m){
            if(b){
            for(int i=0;i<n;i++){
                a[i][j]=s[cur];cur++;
                if(cur==m)break;
            }
                j++;
            }
            else{
                for(int i=n-2;i>0;i--){
                    a[i][j]=s[cur];cur++;j++;
                    if(cur==m)break;
                }
            }
            if(cur==m)break;
            if(b){b=false;}
            else{b=true;}
        }
        
        string ans="";
        for(int i=0;i<n;i++){
            for(int k=0;k<j;k++){
                if(a[i][k]!='1'){ans+=a[i][k];}
            }
        }
        return ans;
    }
};