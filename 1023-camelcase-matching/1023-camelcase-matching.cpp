class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto i:queries){
            int ind=0;bool b=true;
            for(auto j:i){
                // cout<<j<<" "<<ind<<endl;
                if(pattern[ind]==j){ind++;}
                else if(j-'a'>=0 && j-'a'<=25){continue;}
                else{b=false;break;}
            }
            if(ind<pattern.size()){b=false;}
            ans.push_back(b);
        }
        return ans;
    }
};