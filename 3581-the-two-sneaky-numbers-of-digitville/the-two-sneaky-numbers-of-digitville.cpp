class Solution {
    // Shreya
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> result;
        
        // Count frequency of each number
        for (int num : nums) 
        {
            freq[num]++;
        }
        
        // Find numbers that appear twice
        for (auto& [key, value] : freq) 
        {
            if (value == 2) 
            {
                result.push_back(key);
            }
        }
        
        return result;
    }
};