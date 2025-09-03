class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c = 0;
        for(int l=0;l<s.size();l++){
            unordered_map<char, int> m;
            for(int r=l;r<s.size();r++){
                if(m.find(s[r]) != m.end()) break;
                m[s[r]]++;
            }
            c = max(c, (int)m.size());
        }
        return c;
    }
};