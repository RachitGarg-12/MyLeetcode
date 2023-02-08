class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0;
        if(ruleKey=="type"){
            for(auto i:items){
                if(i[0]==ruleValue){ans++;}
            }
        }
        else if(ruleKey=="color"){
            for(auto i:items){
                if(i[1]==ruleValue){ans++;}
            }
        }
        else if(ruleKey=="name"){
            for(auto i:items){
                if(i[2]==ruleValue){ans++;}
            }
        }
        return ans;
    }
};