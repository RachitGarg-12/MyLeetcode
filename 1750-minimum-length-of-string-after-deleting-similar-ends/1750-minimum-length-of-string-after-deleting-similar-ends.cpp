class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                char cur=s[i];
                while(s[i]==cur){
                    i++;
                    if(i>j){return 0;}
                }
                while(s[j]==cur){
                    j--;
                    if(i>j){return 0;}
                }
            }else{break;}
        }
        return j-i+1;
    }
};