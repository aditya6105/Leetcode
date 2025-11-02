class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g = 0;
        int w = 0;
        sort(guards.begin(), guards.end());
        sort(walls.begin(), walls.end());
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g < guards.size() && guards[g][0] == i && guards[g][1] == j){
                    v[i][j] = 2;
                    g++;
                }
                if(w < walls.size() && walls[w][0] == i && walls[w][1] == j){
                    v[i][j] = 1;
                    w++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] == 2){
                    // down
                    int row = i + 1;
                    while(row < m){
                        if(v[row][j] == 1 || v[row][j] == 2) break;
                        else if(v[row][j] == 0 || v[row][j] == 3){
                            v[row][j] = 3;
                            row++;
                        }
                    }
                    // UP
                    row = i - 1;
                    while(row >= 0){
                        if(v[row][j] == 1 || v[row][j] == 2) break;
                        v[row][j] = 3;
                        row--;
                    }
                    // right
                    int col = j + 1;
                    while(col < n){
                        if(v[i][col] == 1 || v[i][col] == 2) break;
                        else if(v[i][col] == 0 || v[i][col] == 3){
                            v[i][col] = 3;
                            col++;
                        }
                    }
                    // LEFT
                    col = j - 1;
                    while(col >= 0){
                        if(v[i][col] == 1 || v[i][col] == 2) break;
                        v[i][col] = 3;
                        col--;
                    }
                }
            }
        }
        int c = 0;
        for(auto it : v){
            for(auto i : it){
                if(i == 0) c++;
            }
        }
        return c;
    }
};