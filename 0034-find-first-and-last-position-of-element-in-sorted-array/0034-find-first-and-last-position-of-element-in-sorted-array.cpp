class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n=a.size();
        vector<int> ans(2,-1);bool b=false;
        for(int i=0;i<n;i++){
            if(b==false && a[i]==t){ans[0]=i;b=true;ans[1]=i;}
            else if(a[i]==t){ans[1]=max(ans[1],i);}
            else if(b){break;}
        }
        return ans;
    }
};