class Solution {
public:
    

    string customSortString(string order, string s) {
        int n=order.size(),m=s.size();
        int cur=1;
        map<char,int> rank;
         for(int i=0;i<n;i++){
             rank[order[i]]=cur;
             cur++;
         }
        for(int i=0;i<26;i++){
            if(rank.find('a'+i)==rank.end()){
                rank['a'+i]=cur;
                cur++;
            }
        }
        sort(s.begin(),s.end(),[&rank] (const auto &a, const auto &b) {return rank[a] < rank[b];});
        return s;
    }
};