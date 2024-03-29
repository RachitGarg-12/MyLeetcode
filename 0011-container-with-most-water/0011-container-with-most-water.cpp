class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        int i=0,j=n-1,ans=0;
        while(i<j){
            int area= min(a[i],a[j])*(j-i);
            ans=max(ans,area);
            if(a[i]>=a[j]){j--;}
            else{i++;}
        }
        return ans;
    }
};

