class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m;
        for(auto it : s) m[it]++;
        
        int maxV = 0;
        int maxC = 0;
        for(auto it : m){
            char ch = it.first;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') maxV = max(maxV, it.second);
            else maxC = max(maxC, it.second);
        }
        return maxC + maxV;
    }
};