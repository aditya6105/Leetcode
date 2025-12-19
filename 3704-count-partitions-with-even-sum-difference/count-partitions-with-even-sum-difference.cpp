class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int total = prefix[n - 1];
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            int leftSum = prefix[i];
            int rightSum = total - leftSum;
            int diff = leftSum - rightSum;

            if (diff % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};
