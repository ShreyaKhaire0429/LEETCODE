class Solution {
    // Shreya
public:
// Shreya
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;  // to track bits appearing once and twice

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;  // add num to ones if not in twos
            twos = (twos ^ num) & ~ones;  // add num to twos if not in ones
        }

        return ones;  
    }
};