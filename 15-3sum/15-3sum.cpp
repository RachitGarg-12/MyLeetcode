class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();sort(a.begin(),a.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(a[i]>0){continue;}
            if( i>0 && a[i]==a[i-1]){continue;}
            int l=i+1,h=n-1;int target=-a[i];
            while(l<h){
                if(a[l]+a[h]==target){ans.push_back({a[l],a[h],a[i]});
                while(l<h && a[l]==a[l+1]){l++;}
                while(l<h && a[h]==a[h-1]){h--;}
                l++;h--;}
                else if(a[l]+a[h]+a[i]<0){l++;}
                else{h--;}
            }
        }
        return ans;
    }
};