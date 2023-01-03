class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> s;int n=a.size(),i=1;
        if(n==1)return stoi(a[0]);
        s.push(stoi(a[0]));
        while(i<n){
             if(a[i]=="*" || a[i]=="+" || a[i]=="-" || a[i]=="/"){
                long long l=s.top();s.pop();
                long long f=s.top();s.pop();
                if(a[i]=="*"){f*=l;}
                if(a[i]=="+"){f+=l;}
                if(a[i]=="-"){f-=l;}
                if(a[i]=="/"){f/=l;}
                s.push(f);
             }
             else{s.push(stoi(a[i]));}
             i++;
        }
        return s.top();
    }
};