class Solution {
    // Shreya
public:
// Shreya
    bool canDivide(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        for (int num : nums) 
        {
            sum += ceil((double)num / divisor);
            if (sum > threshold) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, threshold, mid)) 
            {
                ans = mid;
                right = mid - 1; 
            } 
            else 
            {
                left = mid + 1;  // need larger divisor
            }
        }
        return ans;
    }
};