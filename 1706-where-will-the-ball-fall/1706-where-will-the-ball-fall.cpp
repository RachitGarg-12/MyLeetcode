class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> ans;
        for(int c=0;c<m;c++){
            int j=0;bool b=true;int i=c;
            while(j<n && j>=0 && i>=0 && i<m){
                if(a[j][i]==1 && i<m-1 && a[j][i+1]==1){j++;i++;}
                else if(a[j][i]==-1 && i>0 && a[j][i-1]==-1){i--;j++;}
                else{b=false;break;}
            }
            if(b==false){ans.push_back(-1);}
            else{ans.push_back(i);}
        }
        return ans;
    }
};