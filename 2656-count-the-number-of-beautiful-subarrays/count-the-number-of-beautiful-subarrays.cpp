class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<long long, long long> m;
        m[0]++;
        long long cnt = 0, x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
            if(m[x]) cnt += m[x];
            m[x]++;
        }
        return cnt;
    }
};