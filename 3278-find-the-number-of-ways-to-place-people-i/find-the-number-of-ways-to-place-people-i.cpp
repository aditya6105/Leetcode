class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int c = 0;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) continue;

                // Treat points[i] as A(upper-left), points[j] as B(bottom-right)
                if(points[i][0] <= points[j][0] && points[i][1] >= points[j][1]){ 
                    bool flag = true;
                    for(int k = 0; k < n; k++){
                        if(k == i || k == j) continue;

                        // check if k lies inside or on the rectangle with corners A (i) and B (j)
                        if(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
                           points[j][1] <= points[k][1] && points[k][1] <= points[i][1]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) c++;
                }
            }
        }
        return c;
    }
};