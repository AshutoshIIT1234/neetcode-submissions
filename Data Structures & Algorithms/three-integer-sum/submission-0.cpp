class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
           sort(nums.begin(), nums.end()); // Step 1: Sort
        vector<vector<int>>result;
       int n=nums.size();

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early exit: smallest possible sum already > 0
            if (nums[i] > 0) break;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    // Skip duplicates for l and r
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if (sum < 0) l++;  // Need bigger sum
                else r--;               // Need smaller sum
            }
        }
        
       
        return result;
        
    }
};
