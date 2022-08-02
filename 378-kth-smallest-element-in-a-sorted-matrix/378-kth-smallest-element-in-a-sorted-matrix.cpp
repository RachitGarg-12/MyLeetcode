class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,int> m;int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               m[matrix[i][j]]++;
            }
        }
        int it=1;int ans=-1;
        for(auto i:m){
            if(it==k){ans=i.first;break;}
            if(k-it<m[i.first]){ans=i.first;break;}
            it+= m[i.first];
        }
     return ans;   
    }
};