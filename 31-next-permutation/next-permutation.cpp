class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i + 1]){
                temp = i;
                break;
            }
        }
        if(temp == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=temp;i--){
            if(nums[temp] < nums[i]){
                swap(nums[temp], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+temp+1, nums.end());
    }
};