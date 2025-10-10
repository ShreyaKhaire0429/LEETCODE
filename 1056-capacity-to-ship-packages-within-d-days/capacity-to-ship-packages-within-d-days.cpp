class Solution {
    // Shreya
public:
    bool canShip(vector<int>& weights, int days, int capacity) 
    {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int w : weights) 
        {
            if (currentLoad + w > capacity) 
            {
                requiredDays++;      // need next day
                currentLoad = 0;     // reset for next day
            }
            currentLoad += w;

            if (requiredDays > days) return false;  // early stop if too many days
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = *max_element(weights.begin(), weights.end()); // ship must carry at least the heaviest package
        int right = 0;
        for (int w : weights) right += w; // max capacity = sum of all weights
        int ans = right;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) 
            {
                ans = mid;
                right = mid - 1; // try smaller capacity
            } 
            else 
            {
                left = mid + 1; // need bigger ship
            }
        }
        return ans;
    }
};