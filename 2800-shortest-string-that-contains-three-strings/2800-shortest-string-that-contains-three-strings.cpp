class Solution {
public:
    string merge(string a,string b){
        if(a.find(b) != string::npos)return a;
        for(int i= min(size(a),size(b));i>=0;i--){
            if(a.substr(a.size()-i) == b.substr(0,i))return a + b.substr(i);
        };
        return a + b;
    }
    string helper(string a,string b,string c){
        return merge(merge(a,b),c);
    }
    string minimumString(string a, string b, string c) {
        vector<string> arr = {
           helper(a,b,c) ,
           helper(a,c,b),
           helper(b,a,c),
           helper(b,c,a),
           helper(c,a,b),
           helper(c,b,a)
            };
        sort(arr.begin(),arr.end(),[&](auto a,auto b){
           if(a.size() == b.size())return a < b;
           return a.size() < b.size();
        });
        return arr[0]; 
    }
};