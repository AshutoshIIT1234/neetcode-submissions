class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            // do half mein check karna hao
            if (nums[low] <= nums[mid]) {
                // Left half is sorted
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // target lies in left half
                } else {
                    low = mid + 1;  // target lies in right half
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // target lies in right half
                } else {
                    high = mid - 1;  // target lies in left half
                }
            }

           
        }
         return -1;
    }
};
