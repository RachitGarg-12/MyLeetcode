class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> m;vector<string> ans;
        for(int i=0;i<words2.size();i++){
             map<char,int> temp;
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]]++;
                if(temp[words2[i][j]]>m[words2[i][j]]){m[words2[i][j]]=temp[words2[i][j]];}
            }
        }
    
         for(int i=0;i<words1.size();i++){
             map<char,int> tem=m;
            for(int j=0;j<words1[i].size();j++){
                if(tem[words1[i][j]]==0){continue;}
                tem[words1[i][j]]--;
            }
             bool b=true;
           
            for(auto it:tem){
                if(it.second!=0){b=false;break;}}
             if(b==true){ans.push_back(words1[i]);}
        }
        return ans;
    }
};