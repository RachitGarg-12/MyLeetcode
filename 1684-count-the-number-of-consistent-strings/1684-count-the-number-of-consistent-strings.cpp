class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> present(26,0);
        for(auto i:allowed){
            present[i-'a']=1;
        }
        int ans=0;
        for(auto i:words){
            bool consistent=true;
            for(auto j:i){
                if(present[j-'a']!=1){consistent=false;break;}
            }
            if(consistent)ans++;
        }
        return ans;
    }
};