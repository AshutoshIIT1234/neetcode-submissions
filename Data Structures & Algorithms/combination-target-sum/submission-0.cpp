class Solution {
public:
    void backtrack(vector<int>& nums, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target) continue;   // prune: can't use this number
            
            current.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, current, result); // i, not i+1
            current.pop_back();               // undo choice
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, target, 0, current, result);
        return result;
    }
};
