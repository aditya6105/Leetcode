class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxL = INT_MIN;
        unordered_map<char, int> m;
        while(r < s.size()){
            if(m[s[r]] >= 2){
                while(m[s[r]] >= 2){
                    m[s[l]]--;
                    l++;
                }
            }
            else{
                m[s[r]]++;
                r++;
            }
            maxL = max(maxL, r - l);
        }
        return maxL;
    }
};