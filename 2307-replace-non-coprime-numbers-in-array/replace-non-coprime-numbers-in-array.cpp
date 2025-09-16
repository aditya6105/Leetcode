class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; ) {
            int g = gcd(nums[i], nums[i+1]);
            if (g > 1) {
                // compute LCM safely
                long long l = (1LL * nums[i] * nums[i+1]) / g;
                nums[i] = (int)l;
                nums.erase(nums.begin() + i + 1); // remove the right neighbor
                if (i > 0) --i;  // step back to recheck previous adjacency
            } else {
                ++i; // advance only when no merge happened
            }
        }
        return nums;
    }
};
