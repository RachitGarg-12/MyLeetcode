class Solution {
public:
    bool isValid(string s) {
        int a=0,b=0,c=0;
        vector<int> rec;
        for(auto i:s){
            if(i=='('){a++;rec.push_back(1);}
            if(i==')'){if(a<=0 || rec.back()!=1)return false;
                      else{a--;rec.pop_back();}}
            if(i=='['){b++;rec.push_back(2);}
            if(i==']'){if(b<=0 || rec.back()!=2)return false;
                      else{b--;rec.pop_back();}}
            if(i=='{'){c++;rec.push_back(3);}
            if(i=='}'){if(c<=0 || rec.back()!=3)return false;
                      else{c--;rec.pop_back();}}
        }
        if(a==0 && b==0 && c==0)return true;
        return false;
    }
};