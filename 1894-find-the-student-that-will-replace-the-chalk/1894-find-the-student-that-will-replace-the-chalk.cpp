class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        int n=a.size();int ans=-1;
        long sum=0;
        for(int i=0;i<n;i++){sum+=a[i];}
        long extra=k%sum;
        for(int i=0;i<n;i++){
            if(extra<a[i]){ans=i;break;}
            extra-=a[i];
        }
        return ans;
    }
};