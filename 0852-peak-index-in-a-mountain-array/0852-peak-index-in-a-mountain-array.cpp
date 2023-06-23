class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m==0){l++;continue;}
            if(m==n-1){r--;continue;}
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){return m;}
            else if(arr[m]>arr[m-1] && arr[m]<arr[m+1]){l=m+1;}
            else if(arr[m]<arr[m-1] && arr[m]>arr[m+1]){r=m-1;}
        }
        return -1;
    }
};