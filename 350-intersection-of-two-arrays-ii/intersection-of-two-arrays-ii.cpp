class Solution {
public:
// Shreya
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> freq;
        vector<int> result;

        // Count elements of nums1
        for (int x : nums1) 
        {
            freq[x]++;
        }

        // Check nums2
        for (int y : nums2) 
        {
            if (freq[y] > 0) 
            {
                result.push_back(y);
                freq[y]--;
            }
        }

        return result;
    }
};
