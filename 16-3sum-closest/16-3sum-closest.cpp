class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i<nums.size()-2; i++){
            int x = i+1;
            int y = nums.size()-1;
            while(x<y){
                int temp = nums[i] + nums[x] + nums[y];
                if(temp == target) return temp;
                if(temp < target){
                    x++;
                }
                else if(temp > target){
                    y--;
                }
                if(abs(temp-target) < abs(ans-target)){
                    ans = temp;
                }
            }
        }
        return ans;
    }
};