class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0,r=n-1,ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(letters[m]>target){ans=m;r=m-1;}
            else{l=m+1;}
        }
        return letters[ans];
    }
};