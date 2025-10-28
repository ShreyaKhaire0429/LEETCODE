class Solution {
    // Shreya
public:
    // Shreya

    bool simulate(vector<int> nums, int curr, int dir) {
        int n = nums.size();

        while (curr >= 0 && curr < n) 
        {
            if (nums[curr] == 0) 
            {
                curr += dir;  
            } 
            else 
            {
                nums[curr]--; 
                dir = -dir;   
                curr += dir;  
            }
        }

        for (int val : nums) 
        {
            if (val != 0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 0) 
            {
                if (simulate(nums, i, -1)) count++;
                if (simulate(nums, i, 1)) count++;
            }
        }

        return count;
    }
};