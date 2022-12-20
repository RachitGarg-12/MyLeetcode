class Solution {
public:
    vector<string> s={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    int n;
    void f(string digits,string cur,int i){
        if(i==n){ans.push_back(cur);return;}
        else{
            int ind=digits[i]-'0'-1;
            if(ind==0){f(digits,cur,i+1);}
            else{
            for(auto c:s[ind]){
                f(digits,cur+c,i+1);
            }
            }
        }
        
    }
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0){return {};}
        f(digits,"",0);
        return ans;
    }
};