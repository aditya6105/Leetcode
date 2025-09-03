class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int preSum = 0, c = 0;
        m[0]++;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            if(m.find(preSum - k) != m.end()) c += m[preSum - k];
            m[preSum]++;
        }
        return c;
    }
};