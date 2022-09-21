class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        vector<int> a;
        for(auto x : nums) { if(x%2 == 0) ans+=x;}
        for(auto x : queries){
            if(nums[x[1]]%2 == 0)
                ans-=nums[x[1]];
            nums[x[1]] += x[0];
            if(nums[x[1]]%2 == 0)
                ans+=nums[x[1]];
            a.push_back(ans);
        }
        return a;
    }
};