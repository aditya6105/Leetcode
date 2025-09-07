class Solution {
public:
    vector<int> sumZero(int n) {
        int i = 1;
        vector<int> v;
        if(n % 2 != 0) v.push_back(0);
        n = n/2;
        while(n--){
            v.push_back(i);
            v.push_back(-i);
            i++;
        }
        return v;
    }
};