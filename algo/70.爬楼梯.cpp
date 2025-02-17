/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1;
        int dp2 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = dp1 + dp2;
            dp1 = dp2;
            dp2 = tmp;
        }
        return dp2;
    }
};
// @lc code=end

