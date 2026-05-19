class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        int n =nums.size();
        for(int i=0; i<=n-1;i++)
        {
        for(int j=i+1;j<=n-1;j++){
            if(nums[i]==nums[j]){
                return true;
            }
        }
        }
    return false;
    }
};
