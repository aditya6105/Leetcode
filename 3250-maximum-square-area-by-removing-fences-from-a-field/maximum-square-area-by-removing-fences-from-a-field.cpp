class Solution {
public:
    int MOD = 1e9 + 7;

    unordered_set<int> getEdges(vector<int> fence, int border){
        unordered_set<int> s;
        fence.push_back(1);
        fence.push_back(border);
        sort(fence.begin(), fence.end());
        
        for(int i=0;i<fence.size();i++){
            for(int j=i+1;j<fence.size();j++){
                s.insert(fence[j] - fence[i]);
            }
        }
        return s;
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hHieght = getEdges(hFences, m);
        auto vWidth = getEdges(vFences, n);
        
        int maxC = 0;
        for(auto it : hHieght){
            if(vWidth.count(it)) maxC = max(maxC, it);
        }

        if(maxC == 0) return -1;
        else maxC = (1ll * maxC * maxC) % MOD;

        return maxC;
    }
};