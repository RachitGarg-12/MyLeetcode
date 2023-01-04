class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) {
        int n= arr.size();
        if(n==0){return false;}
        int m= arr[0].size();
        
        
        int  i=0;
        int j=m-1;
        
        while(i<n && j>=0){
            if(arr[i][j]==t){return true;}
            else if(arr[i][j]>t){j--;}
            else{i++;}
        }
        return false;        
    }
};