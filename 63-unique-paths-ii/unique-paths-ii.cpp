class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp) {

        if (i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }

        if (i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = helper(i, j+1, m, n, grid, dp);
        int down  = helper(i+1, j, m, n, grid, dp);

        return dp[i][j] =  right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));

        return helper(0, 0, m, n, obstacleGrid, dp);
    }
};