class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> pos;
        vector<int> preSum;
        int ans = 0;
        for(int i=0;i<fruits.size();i++){
            pos.push_back(fruits[i][0]);
            if(i == 0) preSum.push_back(fruits[i][1]);
            else preSum.push_back(preSum[i - 1] + fruits[i][1]);
        }

        for(int d=0;d<=k/2;d++){ //[when moving left remaining steps = k - d, now going right = k - (2d)]
            //case 1 - starting from left
            int i = startPos - d; // left
            int j = startPos + k - 2 * d; //right

            int left = lower_bound(begin(pos), end(pos), i) - begin(pos); // - begin(pos) to get index
            int right = upper_bound(begin(pos), end(pos), j) - begin(pos) - 1;
            if(left <= right) {   
                int total = preSum[right] - (left > 0 ? preSum[left - 1] : 0);
                ans = max(ans, total);
            }

            //case 2 - starting from right
            j = startPos + d; // right
            i = startPos - (k - 2 * d); // left
            left = lower_bound(begin(pos), end(pos), i) - begin(pos); // - begin(pos) to get index
            right = upper_bound(begin(pos), end(pos), j) - begin(pos) - 1;
            if(left <= right) {   
                int total = preSum[right] - (left > 0 ? preSum[left - 1] : 0);
                ans = max(ans, total);
            }
        }
        return ans;
    }
};