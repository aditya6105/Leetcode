class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto it : nums) m[it]++;
        vector<pair<int, int>> v;
        for(auto it : m) v.push_back({it.second, it.first});
        sort(v.begin(), v.end(), greater<>());
        int ans = v[0].first;
        for(int i=1;i<v.size();i++){
            if(v[i].first == v[i-1].first) ans += v[i].first;
            else break;
        }
        return ans;
    }
};