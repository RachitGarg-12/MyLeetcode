class Solution {
public:
    int getLucky(string s, int k) {
        string dig="";
        for(auto i:s){
            dig+= to_string((i-'a')+1);
        }
        while(k-- && dig.size()!=1){
            int cur=0;
            for(auto i:dig){
                cur+=i-'0';
            }
            dig=to_string(cur);
            // cout<<cur<<" "<<dig<<endl;
        }
        int ans=stoi(dig);
        return ans;
    }
};