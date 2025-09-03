class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int c = 0;
        unordered_map<char, int> m;
        while(r < s.size()){
            if(m.find(s[r]) != m.end() && m[s[r]] > 0){
                while(s[l] != s[r]){
                    m[s[l]]--;
                    l++;
                }
                m[s[l]]--;
                l++;
            }
            m[s[r]]++;
            c = max(c, r - l + 1);
            r++;
        }
        return c;
    }
};