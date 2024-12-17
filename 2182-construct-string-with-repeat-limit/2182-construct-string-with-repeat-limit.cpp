class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        vector<pair<char,int>> freq;
        vector<int> alp(26,0);
        for(auto i:s){
            alp[i-'a']++;
        }
        for(int i=25;i>=0;i--){
            if(alp[i]>0){
                freq.push_back({'a'+i,alp[i]});
            }
        }
        string ans="";
        for(int i=0;i<freq.size();i++){
            char cur=freq[i].first;
            int repeat=freq[i].second;
            if(repeat==0){continue;}
            int num=0;
            while(repeat--){
                ans+=cur;
                num++;
                if(num==repeatLimit && repeat>=1){
                    bool pos=false;
                    for(int j=i+1;j<freq.size();j++){
                        if(freq[j].second>0){
                            pos=true;
                            ans+=freq[j].first;
                            freq[j].second--;
                            break;
                        }
                    }
                    
                    if(pos==false){break;}
                    num=0;
                }  

            }
        }
        return ans;
        
        
        
    }
};