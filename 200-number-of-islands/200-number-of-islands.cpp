class Solution {
public:
    void solve(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        solve(grid, i+1, j);
        solve(grid, i-1, j);
        solve(grid, i, j+1);
        solve(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1')
                {
                    islands++;
                    solve(grid, i, j);
                }
            }
        return islands;
    }
};