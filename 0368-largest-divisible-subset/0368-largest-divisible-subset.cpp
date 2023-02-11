class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        if(n==1){return a;}
        sort(a.begin(),a.end());
        vector<int> score(n,0);
        int mx=0,mxi=0;
        for(int i=1;i<n;i++){
            int count=0;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0 && score[j]+1>score[i]){score[i]=score[j]+1;}
            }
            if(score[i]>mx){mx=score[i];mxi=i;}
        }
        vector<int> ans;
        mx--;
        ans.push_back(a[mxi]);
        int last=a[mxi];
        for(int i=mxi-1;i>=0;i--){
            if(last%a[i]==0 && score[i]==mx){ans.push_back(a[i]);mx--;last=a[i];}
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){ans.push_back(a[0]);}
        return ans;
    }
};