class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(auto i:st){
            if(i=='(' || i=='[' || i=='{'){s.push(i);}
            if(i==')'){if(s.empty() || s.top()!='(')return false;
                      else{s.pop();}}
            if(i==']'){if(s.empty() || s.top()!='[')return false;
                      else{s.pop();}}
            if(i=='}'){if(s.empty() || s.top()!='{')return false;
                      else{s.pop();}}
        }
        if(s.empty())return true;
        return false;
    }
};