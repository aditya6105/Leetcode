class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n, 0);
        vector<int> v;
        for(auto it : nums){
            if(hash[it] == 1) v.push_back(it);
            hash[it]++;
        }
        return v;
    }
};