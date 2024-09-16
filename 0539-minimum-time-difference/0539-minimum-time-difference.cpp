class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        for (const auto& time : timePoints) {
            int hrs = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hrs * 60 + mins);
        }
    
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        minDiff = min(minDiff, 1440 - (minutes.back() - minutes.front()));
        
        return minDiff;
    }
};