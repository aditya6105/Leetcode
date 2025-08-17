class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> v(n+1, 0.0);
        v[0] = 1;
        double probSum = (k == 0) ? 0 : 1;
        for(int i=1;i<=n;i++){
            v[i] = probSum/maxPts;
            if(i < k) probSum += v[i];
            if((i - maxPts) >= 0 && (i - maxPts) < k) probSum -= v[i - maxPts];
        }
        return accumulate(begin(v)+k, end(v), 0.0);
    }
};