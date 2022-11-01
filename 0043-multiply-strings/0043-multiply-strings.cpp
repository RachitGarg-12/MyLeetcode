class Solution {
public:
    string multiply(string s1, string s2) {
        if(s1=="0" || s2=="0")return "0";
        int n=s1.size(),m=s2.size();vector<int> s(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                s[i+j+1] += (s1[i]-'0')*(s2[j]-'0');
                s[i+j] += s[i+j+1]/10;
                s[i+j+1]%=10;
          }
        }
      bool b=true;string ans="";
      for(auto i:s){
          if(i==0 && b==true){continue;}
          else{ans+=to_string(i);b=false;}
      }
      return ans;
    }
};