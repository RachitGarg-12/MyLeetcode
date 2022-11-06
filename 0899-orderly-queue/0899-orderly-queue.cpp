class Solution {
public:
    void bubbleSort(string& s) {
        int n = s.size();
        bool swapped;
        for (int i = 0; i < n; i++) {
            swapped = false;
            for (int j = 0; j < n - 1; j++) {
                if (s[j] > s[j + 1]) {
                    swap(s[j], s[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    
    string orderlyQueue(string s, int k) {
        string ans = s;
        if (k == 1) {
            // "cba" -> "bac" -> "acb" -> "cba" -> ...
            // we only have N swaps here 
            // as it will become the original string after N swaps
            // hence, we can try all N possible swaps and find the lexicographically smallest one
            for (int i = 1; i < s.size(); i++) {
                ans = min(ans, s.substr(i) + s.substr(0, i));
            }
        } else {
            // if k > 1, we can move any character to any position by swapping two adjacent characters
            // By swapping a number of times, 
            // e.g. "cab" 
            // eventually we could have "abc", "acb", "bca", "bac", "cba", "cab" (3 * 2 * 1 = 6 possible arrangements)
            // so the lexicographically smallest string would be the sorted string using bubble sort
            bubbleSort(ans);
            // alternatively, you can use `sort(ans.begin(), ans.end());`
        }
        return ans;
    }
};