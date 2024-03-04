class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int cur=0,ans=0;
        while(i<=j){
            if(power<tokens[i]){
                if(cur>=1){cur--;power+=tokens[j];}
                else{break;}
                j--;
            }
            else{
                power-=tokens[i];
                cur++;
                ans=max(ans,cur);
                i++;
            }
        }
        return ans;
    }
};