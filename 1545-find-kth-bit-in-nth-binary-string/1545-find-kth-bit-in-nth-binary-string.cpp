class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string cur=s;
            reverse(cur.begin(),cur.end());
            for(auto &i:cur){
                if(i=='1'){i='0';}
                else{i='1';}
            }
            s=s+'1'+cur;
        }
        return s[k-1];
    }
};