class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        vector<int> tem(a.begin(),a.end());
        sort(tem.begin(),tem.end());
        int st=0,en=n-1;
        while(st<n && a[st]==tem[st]){st++;}
        while(en>st && a[en]==tem[en]){en--;}
        return en-st+1;
    }
};

      