class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(a[i]==0 && i!=n-1){v.push_back(i);}
        }
        for(auto i:v){
            bool temp=false;
            for(int j=i-1;j>=0;j--){
                if(a[j]+j>i){temp=true;break;}
            }
            if(temp==false)return false;
        }
        return true;
    }
};