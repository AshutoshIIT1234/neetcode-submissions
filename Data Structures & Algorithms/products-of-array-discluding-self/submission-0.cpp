class Solution {
   public:
    int prefix_product(vector<int>& nums, int j) {
        int res = 1;
        for (int i = 0; i < j; i++) {
            res = nums[i] * res;
        }
        return res;
    }
    int suffix_product(vector<int>& nums, int j) {
        int res = 1;
        for (int i = nums.size() - 1; i > j; i--) {
            res = nums[i] * res;
        }
        return res;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        

        for (int i = 0; i < nums.size(); i++) {
            int res = prefix_product(nums, i) * suffix_product(nums, i);
             result.push_back(res);
        }
        return result;
    }
};
