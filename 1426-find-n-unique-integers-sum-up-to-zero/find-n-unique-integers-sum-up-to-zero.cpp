class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 2) return {1, -1};
        vector<int> v;
        for(int i=0;i<n-1;i++){
            v.push_back(i);
        }
        int sum = 0;
        for(int i=0;i<v.size();i++) sum += v[i];
        v.push_back(-(sum));
        return v;
    }
};