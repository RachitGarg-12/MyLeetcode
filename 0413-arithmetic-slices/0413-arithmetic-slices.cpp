class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n==1){return 0;}
        vector<int> len;
        int dif=a[1]-a[0],cur=2;
        for(int i=2;i<n;i++){
            if(a[i]-a[i-1]==dif){cur++;}
            else{
                if(cur>=3){len.push_back(cur);}
                cur=2;dif=a[i]-a[i-1];
            }
        }
        if(cur>=3){len.push_back(cur);}
        int ans=0;
        for(auto i:len){
            ans+=(i*(i-2));
            ans-=(((i*(i-1))/2)-1);
        }
        return ans;
        
    }
};