class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(),a.end());int n=a.size();int cnt=0;
        for(int i=2;i<n;i++){
            int l = 0,h = i-1;
            while(l<h){
                if(a[l]+a[h] > a[i]){cnt += (h-l); h--; }
                else{ l++;}
            }
        }
        return cnt;
    }
};