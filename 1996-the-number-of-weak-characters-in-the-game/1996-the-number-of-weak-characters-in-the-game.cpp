class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        int n=a.size();sort(a.begin(),a.end(),comp);int ans=0; int mx=-1e9;
        for(int i=0;i<n;i++){
            if(mx>a[i][1]){ans++;}
            else{mx=a[i][1];}
        }
        return ans;
    }
};