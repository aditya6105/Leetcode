class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c = 0;
        for(int left=0;left<s.size();left++){
            unordered_set<char> st;
            for(int right=left;right<s.size();right++){
                if(st.find(s[right]) != st.end()){
                    c = max(c, right - left);
                    break;
                }
                st.insert(s[right]);
            }
            c = max(c, (int)st.size());
        }
        return c;
    }
};