class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=1;i<=numRows;i++){
            vector<int> vec = {1};
            int a = 1;
            for(int j=1;j<i;j++){
                a = a * (i - j) / j;
                vec.push_back(a);
            }
            v.push_back(vec);
        }
        return v;
    }
};