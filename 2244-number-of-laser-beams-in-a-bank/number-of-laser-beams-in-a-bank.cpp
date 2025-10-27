class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        int lastE = 1;
        for(auto it : bank){
            int one = 0;
            for(char c : it){
                if(c == '1') one++;
            }
            if(one > 0){
                v.push_back(one * lastE);
                lastE = one;
            }
        }
        int total = 0;
        for(int i=1;i<v.size();i++) total += v[i];
        return total;
    }
};