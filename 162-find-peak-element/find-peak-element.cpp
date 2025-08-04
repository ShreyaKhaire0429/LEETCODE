class Solution {
public:
// Shreya
    int findPeakElement(vector<int>& nums) 
    {
       int left = 0, right = nums.size() - 1;

        while (left < right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) 
            {
                // Look on the left
                right = mid;
            } 
            else 
            {
                // Look on the right
                left = mid + 1;
            }
        }

        return left; // or return right 
    }
};