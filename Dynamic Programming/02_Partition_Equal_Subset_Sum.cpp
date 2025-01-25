#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    bool help(int i, int tar, vector<int>& nums, int n,
              vector<vector<int>>& dp) {
        if (tar == 0)
            return true;
        if (i == n - 1)
            return tar == nums[i];
        if (dp[i][tar] != -1)
            return dp[i][tar];
        int taken = false;
        if (nums[i] <= tar)
            taken = help(i + 1, tar - nums[i], nums, n, dp);
        int notaken = help(i + 1, tar, nums, n, dp);
        return dp[i][tar] = taken || notaken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return help(0, sum / 2, nums, n, dp);
    }
};