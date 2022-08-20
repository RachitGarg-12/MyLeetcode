class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(),a.end());int n=a.size();int ans=0;
        if(n<3){return 0;}
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len=a[i]+a[j];
                int ind=lower_bound(a.begin(),a.end(),len)-a.begin();
                if(ind>j){ans += ind-j-1;}
            }
        }
        return ans;
    }
};