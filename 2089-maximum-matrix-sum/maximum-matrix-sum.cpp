class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> v;
        int c = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] < 0) c++;
                v.push_back(abs(matrix[i][j]));
            }
        }
        long long sum = 0;
        if(c % 2 != 0){
            sort(v.begin(), v.end());
            for(int i=1;i<v.size();i++){
                sum = sum + 1ll * v[i];
            }
            sum = sum - 1ll * v[0];
        }
        else{
            for(auto it : v) sum += 1ll * it;
        }
        return sum;
    }
};