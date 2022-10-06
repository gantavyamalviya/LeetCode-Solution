class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bitset<10001> dp(1);       // 0 is always achievable => dp[0] = 1
        for(int num : nums) 
            dp = dp | dp << num;
        return dp[halfSum];
    }
};