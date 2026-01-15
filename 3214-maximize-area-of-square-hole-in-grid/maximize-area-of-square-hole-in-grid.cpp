class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int Hmax = 1, Vmax = 1;
        int hC = 1, vC = 1;
        
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] == hBars[i - 1] + 1) hC++;
            else hC = 1;
            Hmax = max(Hmax, hC);
        }

        for(int i=1;i<vBars.size();i++){
            if(vBars[i] == vBars[i - 1] + 1) vC++;
            else vC = 1;
            Vmax = max(Vmax, vC);
        }

        int side = min(Vmax, Hmax) + 1;
        return side * side;
    }
};