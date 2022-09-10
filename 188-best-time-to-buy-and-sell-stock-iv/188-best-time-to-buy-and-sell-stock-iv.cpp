class Solution {
public:
    int dp[1002][102][3];
    int solve(int k, vector<int>& prices, int n, int i, int buy){
        
        if(i == n or k == 0) return 0;
        
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        
        int profit;
        
        if(buy == 0){
            profit = max(solve(k, prices, n, i+1, 0), -prices[i] + solve(k, prices, n, i+1, 1));
        }
        if(buy == 1){
            profit = max(solve(k, prices, n, i+1, 1), prices[i] + solve(k-1, prices, n, i+1, 0));
        }
        return dp[i][k][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(k,prices, n, 0, 0);
    }
};