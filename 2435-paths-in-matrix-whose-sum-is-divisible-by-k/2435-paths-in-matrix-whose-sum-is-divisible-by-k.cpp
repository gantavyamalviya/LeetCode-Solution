#define vvvi vector<vector<vector<int>>>
class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int k, int i, int j, int sum, vvvi &dp){
        if(i<0 or i==grid.size() or j <0 or j==grid[0].size()){
            return 0;
        }
        sum =(sum+grid[i][j])%k;
        if(i == grid.size()-1 and j == grid[0].size()-1){
            if(sum%k == 0) return 1;
            else return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        return dp[i][j][sum] = (solve(grid, k, i+1, j, sum,dp)+solve(grid,k,i,j+1,sum,dp))%1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vvvi dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(grid, k, 0, 0, 0,dp);
    }
};