class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
            if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int max_consecutive = 1;
        int current_max = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates — don't reset, don't increment
                continue;
            } else if (nums[i] - nums[i - 1] == 1) {
                // Consecutive — extend the streak
                current_max++;
            } else {
                // Gap found — reset streak
                current_max = 1;
            }
            max_consecutive = max(max_consecutive, current_max);
        }
        return max_consecutive;
    }
};
