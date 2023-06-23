class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()){return findMedianSortedArrays(nums2,nums1);}
        int n1=nums1.size();
        int n2=nums2.size();
        int med=(n1+n2+1)/2;
        int l=0,r=n1,cut1,cut2,l1,r1,l2,r2;
        while(l<=r){
            cut1=l+(r-l)/2;
            cut2=med-cut1;
            l1=(cut1>0)?nums1[cut1-1]:INT_MIN;
            l2=(cut2>0)?nums2[cut2-1]:INT_MIN;
            r1=(cut1<n1)?nums1[cut1]:INT_MAX;
            r2=(cut2<n2)?nums2[cut2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2){return max(l1,l2);}
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2){
                r=cut1-1;
            }
            else{
                l=cut1+1;
            }
        }
        return 0.0;
    }
};