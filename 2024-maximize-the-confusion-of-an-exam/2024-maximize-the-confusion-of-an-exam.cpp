class Solution {
public:
    int count(string s, int k, char ch){
        int n=s.length();
        
        int maxlen=0, bad=0; // count of opposite parity character
        
        int i=0, j=0;
        while(j<n){
            if(s[j]!=ch) bad++; // check if we are acquiring a bad character at rear end
            
            while(i<=j && bad>k){
                char cur=s[i];
                if(cur!=ch) bad--; // releasing bad characters acquired from front end
                i++;
            }
            
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans1=count(answerKey,k,'T');
        int ans2=count(answerKey,k,'F');
        return max(ans1,ans2);
    }
};