class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i, int prev){
        if(i >= nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = 0;
        int not_take = solve(nums, i+1, prev);
        if(prev == -1 or nums[i] > nums[prev]){
            take = 1+solve(nums, i+1, i);
        }
        return dp[i][prev+1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(1+nums.size(), vector<int> (1+nums.size(), -1));
        return solve(nums, 0, -1);
    }
};