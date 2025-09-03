class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0;
        int left = 0;
        int c = 0;
        while(i < s.size()){
            if(m.find(s[i]) != m.end()) left = max(left, m[s[i]] + 1);
            m[s[i]] = i;
            c = max(c, i - left + 1);
            i++;
        }
        return c;
    }
};