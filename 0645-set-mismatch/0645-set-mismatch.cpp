class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(auto x : nums){
            v[x-1]++;
        }
        int x1 = 0, x2 = 0;
        for(int i = 0; i<n; i++){
            if(v[i] == 2){
                x1 = i+1;
            }
            if(v[i] == 0){
                x2 = i+1;
            }
        }
        return {x1,x2};
    }
};