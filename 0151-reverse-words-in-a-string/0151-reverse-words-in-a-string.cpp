class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int strt = 0, end = 0;
        int itrtr = 0;
        while (itrtr < n) {
            while (itrtr < n && s[itrtr] != ' ')
                s[end++] = s[itrtr++];

            if (strt < end) {
                reverse(s.begin() + strt, s.begin() + end); 
                if (end == n) break;
                s[end++] = ' ';
                strt = end;
            }
            itrtr++; 
        }
        if (end > 0 && s[end-1] == ' ')   s.resize(end-1);
       else  s.resize(end);
        return s;
    }
};