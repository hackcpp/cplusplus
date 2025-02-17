/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int dp0 = nums[0];
        int dp1 = max(nums[0], nums[1]);
        int dp2 = 0;

        for (int i = 2; i < nums.size(); i++) {
            dp2 = max(dp0 + nums[i], dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
       
      
};
// @lc code=end

