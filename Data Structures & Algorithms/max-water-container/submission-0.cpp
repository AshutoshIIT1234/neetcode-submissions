class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;

        while (l < r) {
            int water = (r - l) * min(height[l], height[r]);
            maxWater = max(maxWater, water);

            // move the shorter bar
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return maxWater;
    }
};
