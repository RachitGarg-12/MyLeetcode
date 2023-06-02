class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n==1){return 0;}
        int dif=a[1]-a[0],cur=0;
        int ans=0;
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==dif){cur++;}
            else{cur=0;dif=a[i]-a[i-1];}
            ans+=cur;
        }
        return ans;
    }
};