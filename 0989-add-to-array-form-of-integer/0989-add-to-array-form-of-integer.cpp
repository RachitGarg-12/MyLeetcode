class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int s) {
        int n=num.size();
        string k=to_string(s);
        int l=k.size();
        vector<int> ans;
        if(n>=l){
            int carry=0;int j=l-1;
            int sum=0;
            for(int i=n-1;i>=0;i--){
                if(j<0){sum=(num[i])+carry;}
                else{sum=(num[i])+(k[j]-'0')+carry;}
                ans.push_back(sum%10);
                carry = sum/10;
                if(i==0 && carry>0){ans.push_back(carry);}
                j--;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
            int carry=0;int j=n-1;
            int sum=0;
            for(int i=l-1;i>=0;i--){
                if(j<0){sum=(k[i]-'0')+carry;}
                else{sum=(num[j])+(k[i]-'0')+carry;}
                ans.push_back(sum%10);
                carry = sum/10;
                if(i==0 && carry>0){ans.push_back(carry);}
                j--;
            }
            reverse(ans.begin(),ans.end());        
        return ans;
    }
};