class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        
        // Step 2: Bucket by frequency (index = frequency)
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq)
            buckets[count].push_back(num);
        
        // Step 3: Collect top k from highest frequency down
        vector<int> result;
        for (int i = n; i >= 1 && result.size() < k; i--)
            for (int num : buckets[i])
                result.push_back(num);
        
        return result;
    }
};