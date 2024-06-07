class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(auto i:dictionary){
            mp[i]++;
        }
        string ans="",cur="";
        int n=sentence.size();
        for(int i=0;i<n;i++){
            
            if(sentence[i]!=' '){
                cur+=sentence[i];
                if(mp.find(cur)!=mp.end() || i==n-1){
                    ans+=cur;
                    ans+=' ';
                    cur="";
                    while(i<n && sentence[i]!=' '){i++;}
                }
            }
            else{
                ans+=cur;
                ans+=' ';
                cur="";
            }
        }
        if(ans.back()==' '){ans.pop_back();}
        return ans;
    }
};