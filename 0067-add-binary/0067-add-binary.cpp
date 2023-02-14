class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        int i=n-1,j=m-1;
        int carry=0;
        string ans="";
        while(i>=0 && j>=0){
            if((a[i]-'0')+(b[j]-'0')+carry==3){ans+='1';carry=1;}
            else if((a[i]-'0')+(b[j]-'0')+carry==2){ans+='0';carry=1;}
            else if((a[i]-'0')+(b[j]-'0')+carry==1){ans+='1';carry=0;}
            else if((a[i]-'0')+(b[j]-'0')+carry==0){ans+='0';carry=0;}
            i--;j--;
        }
        while(i>=0){
            if(a[i]-'0'+carry==1){ans+='1';carry=0;}
            else if(a[i]-'0'+carry==2){ans+='0';carry=1;}
            else{ans+='0';carry=0;}
            i--;
        }
        while(j>=0){
            if(b[j]-'0'+carry==1){ans+='1';carry=0;}
            else if(b[j]-'0'+carry==2){ans+='0';carry=1;}
            else{ans+='0';carry=0;}
            j--;
        }
        if(carry==1){ans+='1';}
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){return "0";}
        return ans;
    }
};