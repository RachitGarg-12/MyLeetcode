class Solution {
public:
    string convert(string s, int n) {
        if(n==1){return s;}
        if(s.size()<=n){return s;}
        int m=s.length();
        string ans="";int ind=0;
        for(int i=0;i<n;i++){
            ans+=s[i];ind=i;
            int up=i,down=n-1-i;
            if(i==0){
                while(ind+2*down<m){
                    ind += 2*down;
                    ans += s[ind];
                }
                continue;
            }
            else if(i==n-1){
                while(ind+2*up<m){
                    ind+=2*up;
                    ans+=s[ind];
                }
                continue;
            }
           else{ 
            bool d=true;
            while(ind<m){
                cout<<ind<<endl;
                if(d){
                    if(down!=0){ind+=2*down;
                    if(ind>=m)break;
                    ans+=s[ind];}
                    d=false;
                }
                else{
                   if(up!=0){ind+=2*up;
                    if(ind>=m)break;
                    ans+=s[ind];}
                    d=true;
                }
            }
           }
        }
        return ans;
    }
};