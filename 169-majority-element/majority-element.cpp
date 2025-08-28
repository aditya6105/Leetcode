class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(c == 0){
                element = nums[i];
            }
            if(nums[i] == element) c++;
            else c--;
        }
        return element;
    }
};