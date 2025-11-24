class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> v;
        int MOD = 1e5;
        long long val = nums[0];
        if(val % 5 == 0) v.push_back(true);
        else v.push_back(false);
        for(int i=1;i<nums.size();i++){
            val = (2 * val + nums[i]) % MOD;
            if(val % 5) v.push_back(false);
            else v.push_back(true); 
        }
        return v;
    }
};