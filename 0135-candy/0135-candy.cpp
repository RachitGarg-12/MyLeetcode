class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size();
        vector<int> tot(n,1);
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){tot[i]=tot[i-1]+1;}
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1] && tot[i]<=tot[i+1]){tot[i]=tot[i+1]+1;}
        }
        int sum=0;
        for(auto i:tot){sum+=i;}
        return sum;
    }
};