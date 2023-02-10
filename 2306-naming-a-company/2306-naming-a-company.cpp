class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> groups[26];
        for (auto idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                
                long mutuals = 0;
                for (auto ideaA : groups[i]) {
                    if (groups[j].count(ideaA)) {
                        mutuals++;
                    }
                }
                answer += 2 * (groups[i].size() - mutuals) * (groups[j].size() - mutuals);
            }
        }
        
        return answer;
    }
};