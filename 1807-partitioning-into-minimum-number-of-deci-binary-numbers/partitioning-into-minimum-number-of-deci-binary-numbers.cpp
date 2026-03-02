class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        int a = n.size()-1;
        int ans = n[a]-'0';
        return ans;
    }
};