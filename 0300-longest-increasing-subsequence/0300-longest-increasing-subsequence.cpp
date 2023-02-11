class Solution {
public:
    //lis in O(nlogn) using binary search and overwriting new lis
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> lis;
        lis.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>lis.back()){lis.push_back(a[i]);}
            else{
                int ind=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
                lis[ind]=a[i];
            }
        }
        return lis.size();
    }
};