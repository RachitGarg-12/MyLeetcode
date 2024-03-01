class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int o=-1;
        for(auto i:s){if(i=='1'){o++;}}
        string ans="";
        for(int i=0;i<s.size()-1;i++){
            if((i+1)<=o){ans+='1';}
            else{ans+='0';}
        }
        ans+='1';
        return ans;
    }
};