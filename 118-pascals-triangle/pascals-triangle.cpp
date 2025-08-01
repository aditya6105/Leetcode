class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=1;i<=numRows;i++){
            int a = 1;
            vector<int> temp = {1};
            for(int j=1;j<i;j++){
                a = a * (i - j) / j;
                temp.push_back(a);
            }
            v.push_back(temp);
        }
        return v;
    }
};