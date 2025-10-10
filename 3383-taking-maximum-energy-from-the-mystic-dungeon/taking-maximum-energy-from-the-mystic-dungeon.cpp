class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int maxi = INT_MIN;
        for(int i = e.size() - k; i < e.size(); i++){
            int j = i;
            int sum = 0;
            while(j >= 0){
                sum += e[j];
                maxi = max(maxi, sum);
                j -= k;
            }
        }
        return maxi;
    }
};