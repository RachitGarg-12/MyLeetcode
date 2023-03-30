class Solution {
public:
    bool ip4(string s){
        int n=s.size();
        if(n>=4 || n<=0){return false;}
        if(n>1 && s[0]=='0'){return false;}
        if(n && stoi(s)>255){return false;}
        return true;
    }
    bool ip6(string s){
        int n=s.size();
        if(n<=0 || n>4){return false;}
        return true;
    }
    string validIPAddress(string queryIP) {
        bool ipv4=true,ipv6=true;
        string cur="";int count=1;
        bool hexa=false;
        for(auto i:queryIP){
            if(i=='.'){
              ipv6=false;
              if(ipv4==false || ip4(cur)==false){return "Neither";}  
              cur="";count++;
              continue;
            }
            if(i==':'){
                ipv4=false;
                if(ipv6==false || ip6(cur)==false){return "Neither";}
                cur="";count++;
                continue;
            }
            if(!((i-'0'>=0 && i-'0'<=9) || (tolower(i)-'a'>=0 && tolower(i)-'a'<=5))){return "Neither";}
            if((tolower(i)-'a')>=0 && (tolower(i)-'a')<=5){
                if(ipv6==false)return "Neither";
                hexa=true;
                ipv4=false;
            }
            cur+=i;
        }
        if(cur.size()==0){return "Neither";}
        if(ipv4 && count==4 && !hexa && ip4(cur)){return "IPv4";}
        if(ipv6 && count==8 && ip6(cur)){return "IPv6";}
        return "Neither";
    }
};