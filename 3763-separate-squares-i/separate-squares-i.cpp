class Solution {
public:
    double areaBelow(double y, vector<vector<int>>& squares) {
        double area = 0;
        for (auto &s : squares) {
            double bottom = s[1];
            double top = s[1] + s[2];
            double side = s[2];

            if (y <= bottom) continue;
            if (y >= top) area += side * side;
            else area += (y - bottom) * side;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        for (auto &s : squares)
            total += 1.0 * s[2] * s[2];

        double low = 0, high = 1e9;
        for (int i = 0; i < 60; i++) {  // precision control
            double mid = (low + high) / 2;
            if (areaBelow(mid, squares) >= total / 2)
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};
