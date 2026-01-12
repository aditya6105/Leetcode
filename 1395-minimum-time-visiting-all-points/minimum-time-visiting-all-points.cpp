class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int total_dist = 0;
        for(int pts=1;pts<p.size();pts++){
            int x1 = p[pts - 1][0];
            int y1 = p[pts - 1][1];
            int x2 = p[pts][0];
            int y2 = p[pts][1];
            total_dist += max(abs(x2 - x1), abs(y2 - y1));
        }
        return total_dist;
    }
};