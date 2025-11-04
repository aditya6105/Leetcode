class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int count=0;
        int n = v.size();
        int m = s.size();
        for(int i=0;i<m-1;i++){
            if(s[i]==s[i+1]){
                count += min(v[i], v[i+1]);
                v[i+1] = max(v[i], v[i+1]);
            }
        }
        return count;
    }
};