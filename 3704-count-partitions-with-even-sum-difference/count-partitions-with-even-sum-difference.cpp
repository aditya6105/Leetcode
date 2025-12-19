class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> v;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            v.push_back(sum);
        }
        int k = v.size() - 1;
        int c = 0;
        for(int i=0;i<v.size() - 1;i++){
            int x = v[k] - v[i];
            int diff = v[i] - x;
            if(diff % 2 == 0) c++;
        }
        return c;
    }
};