class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n=a.size();
        if(n==0){return {};}
        if(n==1){return {to_string(a[0])};}
        vector<string> res;
        string ans="";
        ans+=to_string(a[0]);
        bool b=true;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1){
                if(ans.back()=='>'){continue;}
                ans+="->";
            }
            else{
                if(ans.back()=='>'){ans+=to_string(a[i-1]);}
                res.push_back(ans);
                ans=to_string(a[i]);
                if(i==n-1){res.push_back(ans);}
            }
        }
        if(ans.back()=='>'){ans+=to_string(a[n-1]);res.push_back(ans);}
        return res;
    }
};