class Solution {
public:
    int dp[202][10001] ;
    bool solve(vector<int>& nums, int sum, int i){
        if(sum == 0)  return true;
        if(sum<0 or i>=size(nums)){
            return false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(nums, sum-nums[i], i+1) || solve(nums, sum, i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(auto x : nums){
            sum+=x;
        }
        if(sum%2 != 0) return false;
        sum/=2;
        return solve(nums, sum, 0);  
    }
};