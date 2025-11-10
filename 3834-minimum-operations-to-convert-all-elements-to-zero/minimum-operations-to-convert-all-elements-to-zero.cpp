class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> v;
        int c = 0;
        for(int i=0;i<nums.size();i++){
            while(!v.empty() && v.back() > nums[i]) v.pop_back();

            if(nums[i] == 0) continue;

            if(v.empty() || v.back() < nums[i]){
                c++;
                v.push_back(nums[i]);
            }
        }
        return c;
    } 
};