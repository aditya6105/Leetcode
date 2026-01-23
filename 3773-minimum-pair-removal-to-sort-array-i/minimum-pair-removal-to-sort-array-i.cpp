class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = -1;

            // find leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // replace nums[idx] and nums[idx+1] with their sum
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }

private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
};
