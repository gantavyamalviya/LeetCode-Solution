class Solution {
public:
    int trap(vector<int>& height) {
        int leftend =0;
        int rightend = height.size()-1;
        int ans = 0;
        int maxleft = height[leftend];
        int maxright = height[rightend];
        while(leftend<=rightend){
            
            maxleft = max(maxleft,height[leftend]);
            maxright = max(maxright,height[rightend]);
            
            ans += min(maxleft,maxright)-min(height[leftend],height[rightend]);
            
            if(height[leftend]<height[rightend])leftend++;
            else{
                rightend--;
            }
            
        }
        return ans;
    }
};