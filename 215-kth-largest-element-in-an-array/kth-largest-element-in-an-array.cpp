class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        for(auto it : nums) p.push(it);
        k -= 1;
        while(k--) p.pop();
        return p.top();
    }
};