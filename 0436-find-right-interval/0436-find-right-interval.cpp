class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            a.push_back({intervals[i][0],intervals[i][1],i});
        }
        sort(a.begin(),a.end());
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            int st=a[i][1];
            int l=i,r=n-1,ans=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[mid][0]>=st){
                    ans=mid;r=mid-1;
                }
                else{l=mid+1;}
            }
            if(ans!=-1){
                res[a[i][2]]=a[ans][2];
            }
        }
        return res;
    }
};