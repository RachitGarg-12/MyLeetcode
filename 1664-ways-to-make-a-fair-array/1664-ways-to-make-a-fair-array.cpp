class Solution {
public:
    int waysToMakeFair(vector<int>& a) {
        int n=a.size();
        vector<int> o(n),bo(n),e(n),be(n);
        int od=0,ev=0;
        for(int i=0;i<n;i++){
            o[i]=od;e[i]=ev;
            if(i%2){od+=a[i];}
            else{ev+=a[i];}
        }
        od=0;ev=0;
        for(int i=n-1;i>=0;i--){
            bo[i]=od;be[i]=ev;
            if(i%2){od+=a[i];}
            else{ev+=a[i];}
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(o[i]+be[i]==e[i]+bo[i]){ans++;}
        }
        return ans;
    }
};