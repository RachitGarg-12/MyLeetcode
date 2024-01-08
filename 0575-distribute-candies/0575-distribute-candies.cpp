class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        n/=2;
        unordered_set<int> s;
        for(auto i:candyType){s.insert(i);}
        if(n>=s.size()){
            return (int)s.size();
        }
        return n;
    }
};