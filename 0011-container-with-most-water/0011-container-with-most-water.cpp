class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        int i=0,j=n-1,ans=0;
        while(i<j){
            ans=max(ans,min(a[i],a[j])*(j-i));
            if(a[i]>=a[j]){j--;}
            else{i++;}
        }
        return ans;
    }
};

