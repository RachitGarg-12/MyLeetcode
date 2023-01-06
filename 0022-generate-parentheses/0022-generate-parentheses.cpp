class Solution {
public:
    vector<string> ans;int t;
    void rec(int i,string p,int score){
        if(i>t){ans.push_back(p);return;}
        if(score==0){p+="(";rec(i+1,p,score+1);}
        else{
            if(score>=t-i){p+=")";rec(i+1,p,score-1);}
            else{
               p+="(";rec(i+1,p,score+1);p.pop_back();
               p+=")";rec(i+1,p,score-1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        t=2*n;string s="";
        rec(1,s,0);
        return ans;
    }
};