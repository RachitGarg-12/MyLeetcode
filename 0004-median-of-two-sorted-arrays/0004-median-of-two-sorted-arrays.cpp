class Solution {
public:
    int n,m;
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int i=0,j=0,k=0;
        vector<int> ans(n+m);
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                ans[k++]=nums1[i++];
            }else{
                ans[k++]=nums2[j++];
            }
        }
        while(i<n){ans[k++]=nums1[i++];}
        while(j<m){ans[k++]=nums2[j++];}
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(),m=nums2.size();
        vector<int> arr=merge(nums1,nums2);
        int tot=n+m;
        if(tot%2){
            return (double)arr[tot/2];
        }

        return (double)(arr[tot/2]+arr[(tot/2)-1])/2;
    }
};