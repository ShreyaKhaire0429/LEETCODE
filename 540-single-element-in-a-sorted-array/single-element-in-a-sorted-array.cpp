class Solution {
public:
// Shreya
    int singleNonDuplicate(vector<int>& nums) 
    {
        int low = 0, high = nums.size() - 1;

        while (low < high) 
        {
            int mid = low + (high - low) / 2;
            
            // Ensure mid is even so we can compare with mid+1
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) 
            {
                // Single element is after this pair
                low = mid + 2;
            } 
            else 
            {
                // Single element is at mid or before
                high = mid;
            }
        }

        return nums[low];
    }
};