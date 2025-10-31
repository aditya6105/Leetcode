class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> v;
        for(auto it : nums){
            if(s.count(it)) v.push_back(it);
            s.insert(it);
        }
        return v;
    }
};