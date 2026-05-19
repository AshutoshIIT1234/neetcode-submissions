class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(), nums.end());
        
        for( int i=0; i<n;i++){
            int j=i+1;
            if(nums[i]== nums[j]){
                return true;
            }
            
        }
        return false;
        
    }
};