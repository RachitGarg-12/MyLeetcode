class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        map<string,int> m;int n=a.size();
        bool b=true;
        int ans=0;
        for(auto i:a){m[i]++;}
        for(int i=0;i<n;i++){
            string rev=a[i];reverse(rev.begin(),rev.end());
            if(rev==a[i]){
                if(b==true && m[rev]%2==1){ans+=2;b=false;m[rev]--;}
                else if(m[rev]>1){ans+=(m[rev]/2)*4;m[rev]=0;}
            }
            else if(m[rev]>0){
                int mn=min(m[a[i]],m[rev]);
                ans+=mn*4;m[a[i]]=0;m[rev]=0;}
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};