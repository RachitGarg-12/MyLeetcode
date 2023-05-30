class Solution {
public:
    bool isBitSet(int& num, int bitIdx){
        //(1 << bitIdx) => only the 'bitIdx'th bit set, rest all 0'S
        if ((num & (1 << bitIdx)) != 0) 
            return true;
        return false;
    }
    void setBit(int& num, int bitIdx){
        num = num | (1 << bitIdx);
    }
    int solve(vector<int>&nums,  map<int, int>&mp, int visited, int operation){
        if (mp.count(visited)) return mp[visited]; //use stored result
        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (isBitSet(visited, i)){continue;}
            for (int j = i + 1; j < nums.size(); j++){
                if (isBitSet(visited, j)){continue;}
                
                int newVisited = visited;
                setBit(newVisited, i); //mark i as visited
                setBit(newVisited, j); //mark j as visited
                //=====================================================================
                int currScore = operation * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, mp, newVisited, operation + 1);
                int totalScore = currScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);
                //=====================================================================
                //rather than unSetting we will use the same old mask in next Iteration
            }
        }
        return mp[visited] = maxScore; //store the result
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int visited = 0;
        map<int,int>mp;
        int ans = solve(nums,mp,visited,1);
        return ans;
        
    }
};