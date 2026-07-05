class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = nums[i];

            // If curr is negative, swapping max and min beforehand
            // simplifies taking max/min afterward.
            if (curr < 0) {
                swap(maxEndingHere, minEndingHere);
            }

            maxEndingHere = max(curr, maxEndingHere * curr);
            minEndingHere = min(curr, minEndingHere * curr);

            result = max(result, maxEndingHere);
        }

        return result;
    }
};
