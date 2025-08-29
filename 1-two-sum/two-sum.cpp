class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(m.find(diff) == m.end()){
                m[nums[i]] = i;
            }
            else return {m[diff], i};
        }
        return {-1};
    }
};