class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int n=path.size();
        bool dir=true;
        int last=0;
        for(int i=n-1;i>=0;i--){
            if(path[i]=='/'){
                if(ans.back()=='/'){continue;}
                else{ans+='/';}
            }
            else{
                string cur="";
                while(i>=0 && path[i]!='/'){
                    cur+=path[i];i--;
                }
                if(i>=0 && path[i]=='/'){i++;}
                if(cur=="."){continue;}
                else if(cur==".."){last++;continue;}
                else if(last==0){ans+=cur;}
                else{last--;}
            }
        }
        if(ans.back()!='/'){ans+='/';}
        reverse(ans.begin(),ans.end());
        if(ans.size()>1 && ans.back()=='/'){ans.pop_back();}
        return ans;
    }
};