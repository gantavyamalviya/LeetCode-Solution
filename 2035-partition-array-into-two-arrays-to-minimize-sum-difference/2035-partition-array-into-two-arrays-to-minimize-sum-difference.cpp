class Solution {
    void dfs(const vector<int>& nums, const int ind, const int to, const int sum, const int m, vector<vector<int>> &p) {
        if (ind > to) {
            p[m].push_back(sum);
            return;
        }
        dfs(nums, ind + 1, to, sum, m, p);
        dfs(nums, ind + 1, to, sum + nums[ind] * 2, m + 1, p);  
    }
    
public:
    int minimumDifference(vector<int>& nums) {
        const int n = nums.size() >> 1;
        vector<vector<vector<int>>> p(2, vector<vector<int>>(n + 1));
        dfs(nums, 0, n - 1, 0, 0, p[0]);
        dfs(nums, n, nums.size() - 1, 0, 0, p[1]);
        const int target = (p[0][n][0] + p[1][n][0]) / 2;
        int r = abs(p[0][n][0] - p[1][n][0]) >> 1;
        for (int i = 1; i < n; ++i) {
            sort(p[0][i].begin(), p[0][i].end());
            for (const int x : p[1][n - i]) {
                const auto t = lower_bound(p[0][i].begin(), p[0][i].end(), target - x);
                if (t != p[0][i].end()) {
                    r = min(r, (*t) + x - target);
                }
            }
        }
        return r;
    }
};