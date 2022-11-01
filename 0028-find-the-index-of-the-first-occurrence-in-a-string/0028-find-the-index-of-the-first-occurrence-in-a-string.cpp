class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();int ans=-1;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,m)==needle){ans=i;break;}
            }
        }
        return ans;
    }
};