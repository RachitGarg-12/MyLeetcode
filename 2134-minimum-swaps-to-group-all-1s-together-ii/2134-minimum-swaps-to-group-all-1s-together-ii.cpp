class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n=a.size();
        int cnt= count(a.begin(),a.end(),1);
        for(int i=0;i<n;i++){a.push_back(a[i]);}
        int cur=0,ans=0;
        for(int i=0;i<cnt;i++){
              if(a[i]==1){cur++;}
        }
        ans=cur;
        for(int i=cnt;i<2*n;i++){
            if(a[i-cnt]==1){cur--;}
            if(a[i]==1){cur++;}
            ans=max(ans,cur);
        }
        return cnt-ans;
    }
};