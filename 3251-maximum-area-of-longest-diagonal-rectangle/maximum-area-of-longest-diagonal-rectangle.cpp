class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        double maxiD = 0.0;
        int maxArea = 0;
        for(auto it : v){
            double d = sqrt(it[0]*it[0] + it[1]*it[1]);
            int area = it[0] * it[1];
            if(maxiD < d){
                maxiD = d;
                maxArea = area;
            }
            else if(maxiD == d) maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};