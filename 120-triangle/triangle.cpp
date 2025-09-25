class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& tri,int x,int y){
        if(x>=tri.size()){return 0;}
        if(dp[x][y]!=INT_MIN){return dp[x][y];}
        return dp[x][y]=min(tri[x][y]+solve(tri,x+1,y),tri[x][y]+solve(tri,x+1,y+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n,vector<int>(n,INT_MIN));
        return solve(triangle,0,0);
    }
};