class Solution {
    // Shreya
public:
// Shreya
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // smallest number
        int second = INT_MAX;  // second smallest number

        for (int n : nums) 
        {
            if (n <= first) 
            {
                first = n;          // update smallest
            } else if (n <= second)
            {
                
                second = n;         // update second smallest
            } 
            else 
            {
                // Found n > first and n > second
                return true;        // triplet exists
            }
        }

        return false;
    }
};