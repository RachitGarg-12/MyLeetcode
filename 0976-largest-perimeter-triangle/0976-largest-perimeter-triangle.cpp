class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(a.begin(),a.end());int n=a.size();
        for(int i=n-3;i>=0;i--){
            if(a[i]+a[i+1]>a[i+2]){return a[i]+a[i+1]+a[i+2];}
        }
      return 0;
    }
};